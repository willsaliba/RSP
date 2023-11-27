#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

/*
This file contains the implementation for an undirected graph
-implemenented with an adjaceny list
-nodes are zero indexed
-DFS traversal implemented (processing = print node)
-BFS traversal implemented (processing = print node)
*/

class Graph {

private:

  int numNodes;
  vector<list<int>> adjList;

  void recursive_DFS(int currNode, vector<bool>& visited) {
    //processing node (printing it)
    cout << currNode << " ";
    visited[currNode] = true;

    //recursing for all neighbours
    for (int neighbour : adjList[currNode]) {
      if (visited[neighbour] == false) recursive_DFS(neighbour, visited);
    }
  }

public:

  Graph(int num) : numNodes(num), adjList(num) {}

  void insert_edge(int nodeA, int nodeB) { //O(1)
    //undirected so adding opposite node to both nodes lists
    adjList[nodeA].push_back(nodeB);
    adjList[nodeB].push_back(nodeA);
  }

  void remove_edge(int nodeA, int nodeB) { //O(m = # edges)
    //undirected so removing opposite node from both nodes lists
    adjList[nodeA].remove(nodeB);
    adjList[nodeB].remove(nodeA);
  }

  bool search_edge(int nodeA, int nodeB) { //O(m = # edges)
    //undricted so only need to search one of the lists
    for (int node : adjList[nodeA]) {
      if (node == nodeB) return true;
    }
    return false;
  }

  void print_graph() {
    for (int i = 0; i < numNodes; i++) {
      cout << "Node " << i << ": ";
      for (int node : adjList[i]) cout << " -> " << node;
      cout << endl;
    }
  }

  void DFS_print(int startNode) { // O(m + n)
    //intialise bool vector to represent visited nodes
    vector<bool> visited(numNodes, false);

    //recursively calling DFS from beginning at startNode
    recursive_DFS(startNode, visited);
    cout << endl;
  }

  void BFS_print(int startNode) { // O(m + n)
    //intialise bool vector to represent visited nodes 
    vector<bool> visited(numNodes, false);
    visited[startNode] = true;

    //create queue for all nodes at each step & adding startNode
    queue<int> activeNodes;
    activeNodes.push(startNode);

    //looping until BFS completes traversing (queue empty)
    while (activeNodes.empty() == false) {
      
      //processing currNode (printing it) by extracting from front 
      int currNode = activeNodes.front();
      cout << currNode << " ";
      activeNodes.pop();

      //adding all neighbouring nodes to back of queue
      for (int neighbour : adjList[currNode]) {
        if (visited[neighbour] == false) {
          activeNodes.push(neighbour);
          visited[neighbour] = true;
        }
      }
    }
    cout << endl; //newline for my OCD
  }

};

int main() {
  Graph g(5);

  //testing insertion
  cout << "\n--Inserting--" << endl;
  g.insert_edge(0, 1);
  g.insert_edge(0, 4);
  g.insert_edge(1, 3);
  g.insert_edge(2, 3);
  g.insert_edge(3, 4);
  g.print_graph(); 

  //testing DFS
  cout << "\n--DFS--" << endl;
  g.DFS_print(0);

  cout << "\n--BFS--" << endl;
  g.BFS_print(0);

  //testing searching
  cout << "\n--Searching--" << endl;
  g.search_edge(0, 1) ? printf("found\n") : printf("not found\n");
  g.search_edge(0, 3) ? printf("found\n") : printf("not found\n");

  //testing removal
  cout << "\n--Removal--" << endl;
  g.remove_edge(1, 3);
  g.print_graph();

  return 0;
}