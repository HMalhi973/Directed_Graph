#ifndef GRAPH_CPP
#define GRAPH_CPP

#include "Graph.hpp"
#include "GraphNode.hpp"
#include <queue>

// TODO: Implement all other methods defined in Graph.hpp here

template <typename T>
Graph<T>::Graph(const std::vector<std::pair<T, T>> &edges){

    for (int i = 0; i < edges.size(); ++i) {
        auto first = edges[i].first;
        auto second = edges[i].second;

        if (_vertices.find(first) == _vertices.end()) {
            addVertex(first);
        }
        if (_vertices.find(second) == _vertices.end()) {
            addVertex(second);
        }

        addEdge(first, second);
    }
}



template <typename T>
Graph<T>::Graph(const std::map<T, std::set<T>> &adjList) : _adjList(adjList) {
    
    for (auto i = adjList.begin(); i != adjList.end(); ++i) {
        auto first = i->first;
        _vertices[first] = GraphNode<T>(first);

        const std::set<T> &neightborVertices = i->second;

        for (auto j = neightborVertices.begin(); j != neightborVertices.end(); ++j) {
            

            if (_vertices.find(*j) == _vertices.end()) {
                _vertices[*j] = GraphNode<T>(*j);
            }

            addEdge(first, *j);
        }
    }
}


//returns size
template <typename T>
int Graph<T>::size() const
{
    return _vertices.size();
}

//adds a vertex
template <typename T>
void Graph<T>::addVertex(T vertex) {
    // checks if vertex exists, if it does, simply return
    if (_vertices.find(vertex) == _vertices.end()) {
        
        //add vertex to graph
        _vertices[vertex] = GraphNode<T>(vertex);
        //map it to an empty set
        _adjList[vertex] = std::set<T>();

    } else {
        return;
    }
}

//checks if an edge between two vertices exixst
template <typename T>
bool Graph<T>::hasEdge(T from, T to) const
{
    auto startVertex = _adjList.find(from);
    //verify if start  vertex exixsts
    if(startVertex == _adjList.end()){
        return false;
    }

    // Obtain the vertices connected to the start vertex
    const std::set<T>& connectedVertices = startVertex->second;
    auto endVertex = connectedVertices.find(to);

    //if both are found return true
    if (startVertex != _adjList.end() && endVertex != connectedVertices.end())
    {
        return true;
    }
    return false;
}

//adds edge from vertex to vertex
template <typename T>
void Graph<T>::addEdge(T from, T to) {

    //check if vertices exist
    if(_adjList.find(from) == _adjList.end()){
        //create from
        addVertex(from);
    }
    if(_adjList.find(to) == _adjList.end()){
        //create from
        addVertex(to);
    }

    //check if edge exists, if so, return, if not add edge
    if (_adjList[from].find(to) != _adjList[from].end()) 
        return;
    else
        _adjList[from].insert(to);
}

//obtain set of connected vertices from certain vertex
template <typename T>
std::optional<std::set<T>> Graph<T>::getNeighbors(T vertex) const{
    //if vertex does not exist return nullopt
    if(_adjList.find(vertex) == _adjList.end()){
        return std::nullopt;
    }

    //obtain the set
   return _adjList.find(vertex)->second;
    
}

template <typename T>
std::vector<T> Graph<T>::BFS(T start) {
    // Create queue
    std::queue<T> queue;
    // Create vector to store the order of traversal
    std::vector<T> traversalOrder;

    // Initialize all vertices as unvisited
    for (auto i = _vertices.begin(); i != _vertices.end(); ++i) {
        GraphNode<T>& node = i->second; // The corresponding GraphNode object

        // Set default values
        node.color = White;
        node.distance = -1;
        node.predecessor = std::nullopt;
    }

    // Set the start vertex for BFS
    _vertices[start].color = Gray;
    _vertices[start].distance = 0;
    _vertices[start].predecessor = std::nullopt;
    queue.push(start);

    // Begin BFS
    while (!queue.empty()) {
        T u = queue.front();
        queue.pop();
        traversalOrder.push_back(u);

        // Check and iterate through neighbors of u
        std::optional<std::set<T>> neighborsOpt = getNeighbors(u);
        if (neighborsOpt) {
            for (auto it = neighborsOpt->begin(); it != neighborsOpt->end(); ++it) {
                T v = *it;
                if (_vertices[v].color == White) {
                    _vertices[v].color = Gray;
                    _vertices[v].distance = _vertices[u].distance + 1;
                    _vertices[v].predecessor = u;
                    queue.push(v);
                }
            }
        }
        _vertices[u].color = Black;
    }

    return traversalOrder;
}



template <typename T>
int Graph<T>::shortestPath(T start, T end)
{
    // Check if start or end are equal
    if (start == end) {
        return 0; 
    }

    // Run BFS 
    BFS(start);

    // Check the distance to the end vertex
    int distanceToEnd = _vertices[end].distance;
  
    return distanceToEnd; // Return the distance to the end vertex
}

template <typename T>
void Graph<T>::DFS_visit(const T &u, int &time, std::list<T> &record){

    /************************** WORK IN PROGRESS ***********************************/
}

template <typename T>
std::list<T> Graph<T>::DFS() {

    /************************** WORK IN PROGRESS ***********************************/
    
    return std::list<T>(); 
}

#endif // GRAPH_CPP