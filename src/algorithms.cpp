#include "algorithms.h"
#include <queue>
#include <limits>
#include <algorithm>
#include <chrono>
#include <thread>
#include <cmath>

using namespace std::chrono;

static void sleep_if_needed(int delayMs) {
    if (delayMs > 0) {
        std::this_thread::sleep_for(std::chrono::milliseconds(delayMs));
    }
}

static double euclideanDistance(const Node& a, const Node& b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return std::sqrt(dx * dx + dy * dy);
}

PathResult dijkstra(const Graph& graph, int source, int target,
                   VisitCallback onVisit, RelaxCallback onRelax, int delayMs) {
    auto startTime = high_resolution_clock::now();
    
    PathResult result;
    int n = graph.nodeCount();
    const double INF = std::numeric_limits<double>::infinity();
    
    std::vector<double> dist(n, INF);
    std::vector<int> parent(n, -1);
    std::vector<bool> visited(n, false);
    
    // Priority queue: (distance, node)
    using Pair = std::pair<double, int>;
    std::priority_queue<Pair, std::vector<Pair>, std::greater<Pair>> pq;
    
    dist[source] = 0.0;
    pq.push({0.0, source});
    
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        
        if (visited[u]) continue;
        
        visited[u] = true;
        result.nodesVisited++;
        
        if (onVisit) {
            onVisit(u);
            sleep_if_needed(delayMs);
        }
        
        // Early termination when target is reached
        if (u == target) break;
        
        // Relax edges
        for (const auto& edge : graph.getAdjList()[u]) {
            int v = edge.to;
            double newDist = dist[u] + edge.weight;
            
            if (newDist < dist[v]) {
                dist[v] = newDist;
                parent[v] = u;
                pq.push({newDist, v});
                
                if (onRelax) {
                    onRelax(u, v, newDist);
                    sleep_if_needed(delayMs);
                }
            }
        }
    }
    
    // Reconstruct path
    result.cost = dist[target];
    if (dist[target] != INF) {
        std::vector<int> path;
        for (int v = target; v != -1; v = parent[v]) {
            path.push_back(v);
        }
        std::reverse(path.begin(), path.end());
        result.path = path;
    }
    
    auto endTime = high_resolution_clock::now();
    result.executionTimeMs = duration_cast<microseconds>(endTime - startTime).count() / 1000.0;
    
    return result;
}

PathResult bellmanFord(const Graph& graph, int source, int target,
                      VisitCallback onVisit, RelaxCallback onRelax, int delayMs) {
    auto startTime = high_resolution_clock::now();
    
    PathResult result;
    int n = graph.nodeCount();
    const double INF = std::numeric_limits<double>::infinity();
    
    std::vector<double> dist(n, INF);
    std::vector<int> parent(n, -1);
    
    dist[source] = 0.0;
    
    // Relax all edges n-1 times
    for (int i = 0; i < n - 1; ++i) {
        bool updated = false;
        
        for (int u = 0; u < n; ++u) {
            if (dist[u] == INF) continue;
            
            for (const auto& edge : graph.getAdjList()[u]) {
                int v = edge.to;
                double newDist = dist[u] + edge.weight;
                
                if (newDist < dist[v]) {
                    dist[v] = newDist;
                    parent[v] = u;
                    updated = true;
                    
                    if (onRelax) {
                        onRelax(u, v, newDist);
                        sleep_if_needed(delayMs);
                    }
                }
            }
        }
        
        // Early termination if no updates
        if (!updated) break;
    }
    
    // Count visited nodes (all reachable nodes)
    for (int i = 0; i < n; ++i) {
        if (dist[i] != INF) {
            result.nodesVisited++;
            if (onVisit) {
                onVisit(i);
            }
        }
    }
    
    // Reconstruct path
    result.cost = dist[target];
    if (dist[target] != INF) {
        std::vector<int> path;
        for (int v = target; v != -1; v = parent[v]) {
            path.push_back(v);
        }
        std::reverse(path.begin(), path.end());
        result.path = path;
    }
    
    auto endTime = high_resolution_clock::now();
    result.executionTimeMs = duration_cast<microseconds>(endTime - startTime).count() / 1000.0;
    
    return result;
}

PathResult aStar(const Graph& graph, int source, int target,
                VisitCallback onVisit, RelaxCallback onRelax, int delayMs) {
    auto startTime = high_resolution_clock::now();
    
    PathResult result;
    int n = graph.nodeCount();
    const double INF = std::numeric_limits<double>::infinity();
    
    std::vector<double> gScore(n, INF);  // Cost from source
    std::vector<double> fScore(n, INF);  // Estimated total cost
    std::vector<int> parent(n, -1);
    std::vector<bool> visited(n, false);
    
    // Priority queue: (fScore, node)
    using Pair = std::pair<double, int>;
    std::priority_queue<Pair, std::vector<Pair>, std::greater<Pair>> openSet;
    
    gScore[source] = 0.0;
    fScore[source] = euclideanDistance(graph.getNode(source), graph.getNode(target));
    openSet.push({fScore[source], source});
    
    while (!openSet.empty()) {
        auto [f, u] = openSet.top();
        openSet.pop();
        
        if (visited[u]) continue;
        
        visited[u] = true;
        result.nodesVisited++;
        
        if (onVisit) {
            onVisit(u);
            sleep_if_needed(delayMs);
        }
        
        // Target reached
        if (u == target) break;
        
        // Explore neighbors
        for (const auto& edge : graph.getAdjList()[u]) {
            int v = edge.to;
            double tentativeGScore = gScore[u] + edge.weight;
            
            if (tentativeGScore < gScore[v]) {
                parent[v] = u;
                gScore[v] = tentativeGScore;
                fScore[v] = gScore[v] + euclideanDistance(graph.getNode(v), graph.getNode(target));
                openSet.push({fScore[v], v});
                
                if (onRelax) {
                    onRelax(u, v, gScore[v]);
                    sleep_if_needed(delayMs);
                }
            }
        }
    }
    
    // Reconstruct path
    result.cost = gScore[target];
    if (gScore[target] != INF) {
        std::vector<int> path;
        for (int v = target; v != -1; v = parent[v]) {
            path.push_back(v);
        }
        std::reverse(path.begin(), path.end());
        result.path = path;
    }
    
    auto endTime = high_resolution_clock::now();
    result.executionTimeMs = duration_cast<microseconds>(endTime - startTime).count() / 1000.0;
    
    return result;
}
