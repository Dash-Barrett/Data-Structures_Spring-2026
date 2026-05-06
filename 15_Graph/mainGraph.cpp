#include "Graph.hpp"
#include <string>
using namespace std;

int main(void){
    // Graph<string> knowledge;
    // knowledge.insertVertex("AVL");
    // knowledge.insertVertex("BST");
    // knowledge.insertVertex("Trie");
    // knowledge.insertVertex("Heap");

    // knowledge.insertEdge("BST","AVL");
    // knowledge.insertEdge("BST","Trie");
    // knowledge.insertEdge("BST", "Heap");
    // knowledge.print();

    Graph<string> a;
    a.insertVertex("A");
    a.insertVertex("B");
    a.insertVertex("C");
    a.insertVertex("D");
    a.insertVertex("E");
    a.insertVertex("F");
    a.insertVertex("G");
    a.insertVertex("H");
    a.insertVertex("S");

    a.insertEdge("A", "B");
    a.insertEdge("A", "S");
    a.insertEdge("C", "S");
    a.insertEdge("G", "S");
    a.insertEdge("C", "F");
    a.insertEdge("C", "E");
    a.insertEdge("C", "D");
    a.insertEdge("E", "H");
    a.insertEdge("G", "H");
    a.insertEdge("F", "G");

    a.DFS();
    /* TODO
    Create a disconnected graph
    Update DFS to traverse all the nodes of this graph
    */
    a.BFS();

    cout << a.shortestPath("A", "F") << endl;
    cout << a.shortestPath("A", "D") << endl;
    return 0;
}