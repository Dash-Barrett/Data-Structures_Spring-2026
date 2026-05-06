#include "Graph.hpp"
#include <iostream>
#include <queue>

template<typename T>
void Graph<T>::insertVertex(const T& val){
    if(getVertexIndex(val) != -1){
        cout << "insertVertex: vertex already in use" << endl;
        return;
    }
    vertices.push_back(val); // Add the new vertex
    vector<int> tmp;
    edges.push_back(tmp); // Empty list of neighbors for the new vertex
}

template<typename T>
int Graph<T>::getVertexIndex(const T& val) const{
    int i = 0;
    for (const auto& v: vertices){
        if(v == val){
            return i;
        }
        i++;
    }
    return -1;
}

template<typename T>
void Graph<T>::insertEdge(const T& v1, const T& v2){
    int i1 = getVertexIndex(v1), i2 = getVertexIndex(v2);
    if(i1 == -1 || i2 == -1){
        cout << "insertEdge: Incorrect vertices\n";
        return;
    }
    edges[i1].push_back(i2);
    if(i1 != i2){
        edges[i2].push_back(i1);
    }
}

template<typename T>
void Graph<T>::print() const{
    for (int i = 0; i < vertices.size(); i++){
        cout << "{ " << vertices[i] << ": ";
        for(int j = 0; j < edges[i].size(); j++){
            cout << vertices[edges[i][j]] << " ";
        }
        cout << "}" << endl;
    }
    
}

template<typename T>
void Graph<T>::DFS() const{
    if(vertices.empty()){
        return;
    }
    vector<bool> visited(vertices.size(), false);
    DFS(0, visited);
}

template<typename T>
void Graph<T>::DFS(int i, vector<bool>& visited) const{
    visited[i] = true;
    cout << vertices[i] << " -> ";

    // Look through all neighbors
    for(int j : edges[i]){
        if(!visited[j]){
            DFS(j, visited);
        }
    }
}

template<typename T>
void Graph<T>::BFS(int start) const{
    if(vertices.empty() || start < 0 || start >= vertices.size()){
        return;
    }
    vector<bool> discovered(vertices.size(), false);
    queue<int> where_to_go;
    where_to_go.push(start);
    discovered[start] = true;

    while(!where_to_go.empty()){
        int cur = where_to_go.front();
        cout << vertices[cur];
        where_to_go.pop();
        
        // Explore Neighbors
        for(int j : edges[cur]){
            if(!discovered[j]){
                where_to_go.push(j);
                discovered[j] = true;
            }
        }
    }
}

template<typename T>
int Graph<T>::shortestPath(const T& src, const T& dest) const{
    // Find indices
    int i_src = getVertexIndex(src), i_dest = getVertexIndex(dest);
    // Check Edge Cases
    if(i_src == -1 || i_dest == -1){
        cout << "shortestPath: incorrect indices\n";
        return -1;
    }
    if(i_src == i_dest){
        return 0;
    }
    // Create Distances Vector
    vector<int> distances(vertices.size());

    // Set initial distances
    for(int i = 0; i < distances.size(); i++){
        distances[i] = (i == i_src ? 0 : -1);
    }

    // Perform BFS and update distances
    queue<int> q;
    q.push(i_src);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        
        // Check Neighbors
        for(int i : edges[cur]){
            if(distances[i] == -1){
                distances[i] = distances[cur] + 1;
                q.push(1);
            }
            if(i == i_dest) {
                return distances[i];
            }
        }
    }
    return -1;
}