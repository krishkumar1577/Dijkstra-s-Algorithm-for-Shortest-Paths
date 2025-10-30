#pragma once

#include <vector>
#include <string>

// Represents a node in the graph with spatial coordinates for visualization
struct Node {
    int id;
    float x, y;  // Position for visualization and A* heuristic
    
    Node(int id = 0, float x = 0.0f, float y = 0.0f) : id(id), x(x), y(y) {}
};

// Represents a weighted edge
struct Edge {
    int to;
    double weight;
    
    Edge(int to = 0, double weight = 0.0) : to(to), weight(weight) {}
};

// Graph using adjacency list representation
class Graph {
public:
    Graph(bool directed = false);
    
    // Add a node with optional position
    int addNode(float x = 0.0f, float y = 0.0f);
    
    // Add a weighted edge
    void addEdge(int from, int to, double weight);
    
    // Getters
    int nodeCount() const { return static_cast<int>(nodes_.size()); }
    const std::vector<Node>& getNodes() const { return nodes_; }
    const std::vector<std::vector<Edge>>& getAdjList() const { return adjList_; }
    const Node& getNode(int id) const { return nodes_[id]; }
    
    // Generate a random geometric graph for testing
    static Graph generateRandomGeometric(int numNodes, double connectionRadius, 
                                        unsigned seed = 42, bool directed = false);
    
    // Load from file (format: edges with weights)
    static Graph loadFromFile(const std::string& filename, bool directed = false);

private:
    bool directed_;
    std::vector<Node> nodes_;
    std::vector<std::vector<Edge>> adjList_;
};
