#ifndef GRAPH_HPP
#define GRAPH_HPP
#include <vector>
using namespace std;

template<typename T>
class Graph{
private:
    vector<T> vertices;
    vector<vector<int>> edges;
    int getVertexIndex(const T& val) const;
    void DFS(int i, vector<bool>& visited) const;
public:
    void insertVertex(const T& val);
    void insertEdge(const T& v1, const T& v2);
    void print() const;

    void DFS() const;
    void BFS(int start = 0) const;
    int shortestPath(const T& src, const T& dest) const;
    bool isConnected() const;
};

#include "Graph.tpp"

#endif