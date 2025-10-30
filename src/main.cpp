#include "graph.h"
#include "algorithms.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

void printBanner() {
    std::cout << "\n╔════════════════════════════════════════════════════════════╗\n";
    std::cout << "║    DIJKSTRA'S SHORTEST PATH VISUALIZER (Console Mode)     ║\n";
    std::cout << "╚════════════════════════════════════════════════════════════╝\n\n";
}

void printGraph(const Graph& g, const std::vector<int>& path = {}, int source = -1, int target = -1) {
    std::cout << "\n┌─────────────────────────────────────┐\n";
    std::cout << "│  GRAPH STRUCTURE                    │\n";
    std::cout << "└─────────────────────────────────────┘\n\n";
    
    std::cout << "Nodes: " << g.nodeCount() << "\n\n";
    
    std::cout << "Edges:\n";
    for (int u = 0; u < g.nodeCount(); ++u) {
        for (const auto& edge : g.getAdjList()[u]) {
            if (u < edge.to) {  // Print each edge once
                std::cout << "  Node " << u << " ←→ Node " << edge.to 
                          << " [weight: " << std::fixed << std::setprecision(1) << edge.weight << "]";
                
                // Check if this edge is in the path
                bool inPath = false;
                for (size_t i = 0; i + 1 < path.size(); ++i) {
                    if ((path[i] == u && path[i+1] == edge.to) || 
                        (path[i] == edge.to && path[i+1] == u)) {
                        inPath = true;
                        break;
                    }
                }
                if (inPath) {
                    std::cout << " ★ IN SHORTEST PATH ★";
                }
                std::cout << "\n";
            }
        }
    }
    
    if (source >= 0) {
        std::cout << "\n🔵 SOURCE: Node " << source << "\n";
    }
    if (target >= 0) {
        std::cout << "🎯 TARGET: Node " << target << "\n";
    }
}

void visualizeAlgorithm(const Graph& g, int source, int target, const std::string& algName, PathResult result) {
    std::cout << "\n\n";
    std::cout << "╔════════════════════════════════════════════════════════════╗\n";
    std::cout << "║  ALGORITHM: " << std::left << std::setw(47) << algName << "║\n";
    std::cout << "╚════════════════════════════════════════════════════════════╝\n\n";
    
    std::cout << "Running from Node " << source << " to Node " << target << "...\n\n";
    
    if (result.path.empty()) {
        std::cout << "❌ No path found!\n";
        return;
    }
    
    std::cout << "✅ Path Found!\n\n";
    
    std::cout << "┌─────────────────────────────────────┐\n";
    std::cout << "│  RESULTS                            │\n";
    std::cout << "└─────────────────────────────────────┘\n\n";
    
    std::cout << "  📏 Path Cost:       " << std::fixed << std::setprecision(2) 
              << result.cost << "\n";
    std::cout << "  👣 Nodes Visited:   " << result.nodesVisited << "\n";
    std::cout << "  ⚡ Execution Time:  " << std::fixed << std::setprecision(3) 
              << result.executionTimeMs << " ms\n\n";
    
    std::cout << "  🛣️  SHORTEST PATH:\n\n";
    std::cout << "     ";
    for (size_t i = 0; i < result.path.size(); ++i) {
        std::cout << "Node " << result.path[i];
        if (i < result.path.size() - 1) {
            std::cout << "  →  ";
        }
    }
    std::cout << "\n\n";
    
    // Print the graph with the path highlighted
    printGraph(g, result.path, source, target);
}

void runInteractive() {
    printBanner();
    
    std::cout << "📝 Build your graph interactively!\n\n";
    
    int numNodes;
    std::cout << "How many nodes do you want? (3-20): ";
    std::cin >> numNodes;
    
    if (numNodes < 3 || numNodes > 20) {
        std::cout << "Using default: 6 nodes\n";
        numNodes = 6;
    }
    
    Graph g(false);
    for (int i = 0; i < numNodes; ++i) {
        g.addNode(0, 0);  // Positions don't matter for console
    }
    
    std::cout << "\nAdded " << numNodes << " nodes (0 to " << (numNodes-1) << ")\n\n";
    
    std::cout << "Now add edges. Enter pairs of nodes and weights.\n";
    std::cout << "Format: from_node to_node weight\n";
    std::cout << "Example: 0 1 5.0\n";
    std::cout << "Enter -1 -1 -1 to finish\n\n";
    
    int edgeCount = 0;
    while (true) {
        int from, to;
        double weight;
        
        std::cout << "Edge " << (edgeCount + 1) << ": ";
        std::cin >> from >> to >> weight;
        
        if (from == -1) break;
        
        if (from >= 0 && from < numNodes && to >= 0 && to < numNodes && from != to) {
            g.addEdge(from, to, weight);
            std::cout << "  ✓ Added: Node " << from << " ←→ Node " << to 
                      << " [weight: " << weight << "]\n";
            edgeCount++;
        } else {
            std::cout << "  ❌ Invalid nodes. Try again.\n";
        }
    }
    
    if (edgeCount == 0) {
        std::cout << "\n⚠️  No edges added. Creating a sample graph...\n";
        // Create a simple path graph
        for (int i = 0; i < numNodes - 1; ++i) {
            g.addEdge(i, i+1, (i+1) * 10.0);
        }
        if (numNodes >= 4) {
            g.addEdge(0, numNodes-1, 25.0);  // Shortcut
        }
    }
    
    printGraph(g);
    
    int source, target;
    std::cout << "\n\nEnter source node (0-" << (numNodes-1) << "): ";
    std::cin >> source;
    std::cout << "Enter target node (0-" << (numNodes-1) << "): ";
    std::cin >> target;
    
    if (source < 0 || source >= numNodes || target < 0 || target >= numNodes) {
        source = 0;
        target = numNodes - 1;
        std::cout << "Invalid input. Using source=0, target=" << target << "\n";
    }
    
    std::cout << "\n\nChoose algorithm:\n";
    std::cout << "  1. Dijkstra's Algorithm\n";
    std::cout << "  2. Bellman-Ford Algorithm\n";
    std::cout << "  3. A* Algorithm\n";
    std::cout << "  4. Compare All Three\n";
    std::cout << "\nChoice (1-4): ";
    
    int choice;
    std::cin >> choice;
    
    if (choice == 4) {
        // Compare all
        std::cout << "\n\n";
        std::cout << "═══════════════════════════════════════════════════════════\n";
        std::cout << "  COMPARING ALL THREE ALGORITHMS\n";
        std::cout << "═══════════════════════════════════════════════════════════\n";
        
        PathResult r1 = dijkstra(g, source, target);
        PathResult r2 = bellmanFord(g, source, target);
        PathResult r3 = aStar(g, source, target);
        
        std::cout << "\n\n";
        std::cout << std::left << std::setw(20) << "Algorithm"
                  << std::setw(15) << "Time (ms)"
                  << std::setw(15) << "Path Cost"
                  << std::setw(15) << "Nodes Visited" << "\n";
        std::cout << std::string(65, '─') << "\n";
        
        std::cout << std::left << std::setw(20) << "Dijkstra"
                  << std::setw(15) << std::fixed << std::setprecision(3) << r1.executionTimeMs
                  << std::setw(15) << std::fixed << std::setprecision(2) << r1.cost
                  << std::setw(15) << r1.nodesVisited << "\n";
        
        std::cout << std::left << std::setw(20) << "Bellman-Ford"
                  << std::setw(15) << std::fixed << std::setprecision(3) << r2.executionTimeMs
                  << std::setw(15) << std::fixed << std::setprecision(2) << r2.cost
                  << std::setw(15) << r2.nodesVisited << "\n";
        
        std::cout << std::left << std::setw(20) << "A*"
                  << std::setw(15) << std::fixed << std::setprecision(3) << r3.executionTimeMs
                  << std::setw(15) << std::fixed << std::setprecision(2) << r3.cost
                  << std::setw(15) << r3.nodesVisited << "\n";
        
        std::cout << std::string(65, '─') << "\n\n";
        
        std::cout << "🏆 Fastest: ";
        if (r3.executionTimeMs <= r1.executionTimeMs && r3.executionTimeMs <= r2.executionTimeMs) {
            std::cout << "A*\n";
        } else if (r1.executionTimeMs <= r2.executionTimeMs) {
            std::cout << "Dijkstra\n";
        } else {
            std::cout << "Bellman-Ford\n";
        }
        
        std::cout << "🎯 Most Efficient: ";
        if (r3.nodesVisited <= r1.nodesVisited && r3.nodesVisited <= r2.nodesVisited) {
            std::cout << "A* (visited " << r3.nodesVisited << " nodes)\n";
        } else if (r1.nodesVisited <= r2.nodesVisited) {
            std::cout << "Dijkstra (visited " << r1.nodesVisited << " nodes)\n";
        } else {
            std::cout << "Bellman-Ford (visited " << r2.nodesVisited << " nodes)\n";
        }
        
        visualizeAlgorithm(g, source, target, "Dijkstra (Winner's Path)", r1);
        
    } else {
        PathResult result;
        std::string algName;
        
        switch(choice) {
            case 1:
                result = dijkstra(g, source, target);
                algName = "Dijkstra's Algorithm";
                break;
            case 2:
                result = bellmanFord(g, source, target);
                algName = "Bellman-Ford Algorithm";
                break;
            case 3:
                result = aStar(g, source, target);
                algName = "A* Algorithm";
                break;
            default:
                result = dijkstra(g, source, target);
                algName = "Dijkstra's Algorithm (default)";
        }
        
        visualizeAlgorithm(g, source, target, algName, result);
    }
    
    std::cout << "\n\n";
}

int main(int argc, char** argv) {
    if (argc > 1 && std::string(argv[1]) == "--demo") {
        printBanner();
        std::cout << "Running demo with sample graph...\n\n";
        
        Graph g = Graph::generateRandomGeometric(8, 300, 42, false);
        
        printGraph(g);
        
        visualizeAlgorithm(g, 0, 7, "Dijkstra's Algorithm", dijkstra(g, 0, 7));
        
    } else if (argc > 1 && std::string(argv[1]) == "--help") {
        std::cout << "\nDijkstra's Shortest Path Visualizer (Console Mode)\n";
        std::cout << "==================================================\n\n";
        std::cout << "Usage:\n";
        std::cout << "  ./shortest_path          Interactive mode\n";
        std::cout << "  ./shortest_path --demo   Quick demo\n";
        std::cout << "  ./shortest_path --help   This help\n\n";
    } else {
        runInteractive();
    }
    
    return 0;
}
