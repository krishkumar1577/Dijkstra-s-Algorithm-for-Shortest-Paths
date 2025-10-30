#include "graph.h"
#include <random>
#include <cmath>
#include <fstream>
#include <sstream>
#include <stdexcept>

Graph::Graph(bool directed) : directed_(directed) {}

int Graph::addNode(float x, float y) {
    int id = static_cast<int>(nodes_.size());
    nodes_.emplace_back(id, x, y);
    adjList_.emplace_back();
    return id;
}

void Graph::addEdge(int from, int to, double weight) {
    if (from < 0 || from >= nodeCount() || to < 0 || to >= nodeCount()) {
        throw std::out_of_range("Invalid node index");
    }
    
    adjList_[from].emplace_back(to, weight);
    
    // For undirected graphs, add reverse edge
    if (!directed_) {
        adjList_[to].emplace_back(from, weight);
    }
}

Graph Graph::generateRandomGeometric(int numNodes, double connectionRadius, 
                                     unsigned seed, bool directed) {
    Graph g(directed);
    std::mt19937 rng(seed);
    std::uniform_real_distribution<float> dist(50.0f, 950.0f);
    
    // Create nodes with random positions
    for (int i = 0; i < numNodes; ++i) {
        g.addNode(dist(rng), dist(rng));
    }
    
    // Connect nodes within the connection radius
    for (int i = 0; i < numNodes; ++i) {
        for (int j = i + 1; j < numNodes; ++j) {
            float dx = g.nodes_[i].x - g.nodes_[j].x;
            float dy = g.nodes_[i].y - g.nodes_[j].y;
            double distance = std::sqrt(dx * dx + dy * dy);
            
            if (distance <= connectionRadius) {
                g.addEdge(i, j, distance);
            }
        }
    }
    
    return g;
}

Graph Graph::loadFromFile(const std::string& filename, bool directed) {
    Graph g(directed);
    std::ifstream file(filename);
    
    if (!file.is_open()) {
        throw std::runtime_error("Cannot open file: " + filename);
    }
    
    int numNodes;
    file >> numNodes;
    
    // Add nodes with default positions
    for (int i = 0; i < numNodes; ++i) {
        g.addNode(100.0f + (i % 10) * 80.0f, 100.0f + (i / 10) * 80.0f);
    }
    
    // Read edges
    int from, to;
    double weight;
    while (file >> from >> to >> weight) {
        g.addEdge(from, to, weight);
    }
    
    return g;
}
