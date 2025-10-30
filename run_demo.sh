#!/bin/bash

# Simple demonstration of Dijkstra's Algorithm
# This creates a small graph and finds the shortest path

echo "╔════════════════════════════════════════════════════════════╗"
echo "║    DIJKSTRA'S ALGORITHM - INTERACTIVE DEMO                ║"
echo "╚════════════════════════════════════════════════════════════╝"
echo ""
echo "This demo will create a simple 6-node graph and find shortest paths."
echo ""
echo "Graph structure:"
echo "     (0)---5---(1)"
echo "      |    \\   |"
echo "      2     8  3"
echo "      |      \\ |"
echo "     (2)---1---(3)---4---(5)"
echo "      |        |"
echo "      10       2"
echo "      |        |"
echo "     (4)-------(6)"
echo ""

# Create input file
cat << EOF > /tmp/graph_input.txt
6
0
5
0 1 5
0 2 2
0 3 8
1 3 3
2 3 1
3 5 4
2 4 10
3 6 2
4 6 1
-1 -1 -1
0
5
1
EOF

echo "Running Dijkstra's algorithm from Node 0 to Node 5..."
echo ""

cd "$(dirname "$0")/build"
./shortest_path_console < /tmp/graph_input.txt

echo ""
echo "Try creating your own graph interactively:"
echo "  ./build/shortest_path_console"
echo ""
