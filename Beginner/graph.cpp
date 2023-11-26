#include <iostream>
#include <vector>
#include <list>
using namespace std;

/*
This file contains the implementation for an undirected graph
-implemenented with an adjaceny list
-nodes are zero indexed
*/

class Graph {

private:

  int numNodes;
  vector<list<int>> adjList;

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