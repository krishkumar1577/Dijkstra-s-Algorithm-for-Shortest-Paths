#pragma once

#include "graph.h"
#include <vector>
#include <functional>
#include <limits>

// Result from running a shortest path algorithm
struct PathResult {
    std::vector<int> path;      // Sequence of node IDs from source to target
    double cost;                 // Total path cost
    int nodesVisited;            // Number of nodes explored
    double executionTimeMs;      // Execution time in milliseconds
    
    PathResult() : cost(std::numeric_limits<double>::infinity()), 
                   nodesVisited(0), executionTimeMs(0.0) {}
};

// Callbacks for visualization
using VisitCallback = std::function<void(int nodeId)>;
using RelaxCallback = std::function<void(int from, int to, double newDist)>;

// Dijkstra's algorithm
PathResult dijkstra(const Graph& graph, int source, int target,
                   VisitCallback onVisit = nullptr,
                   RelaxCallback onRelax = nullptr,
                   int delayMs = 0);

// Bellman-Ford algorithm
PathResult bellmanFord(const Graph& graph, int source, int target,
                      VisitCallback onVisit = nullptr,
                      RelaxCallback onRelax = nullptr,
                      int delayMs = 0);

// A* algorithm (uses Euclidean distance heuristic)
PathResult aStar(const Graph& graph, int source, int target,
                VisitCallback onVisit = nullptr,
                RelaxCallback onRelax = nullptr,
                int delayMs = 0);
