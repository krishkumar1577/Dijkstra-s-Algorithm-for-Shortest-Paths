# Dijkstra's Algorithm for Shortest Paths# Dijkstra's Algorithm for Shortest Paths# Dijkstra's Algorithm for Shortest Paths



Visualize and compare shortest path algorithms: **Dijkstra**, **Bellman-Ford**, and **A\***.



## Quick Start**An interactive visualization of shortest path algorithms where YOU build the graph!****An interactive visualization of shortest path algorithms where YOU build the graph!**



```bash

# Build

mkdir build && cd build## ✨ Features## ✨ Features

cmake ..

make



# Run- **🖱️ Interactive Graph Building**: Click to add nodes, connect them with edges- **🖱️ Interactive Graph Building**: Click to add nodes, connect them with edges

./shortest_path

```- **🎯 Visual Path Finding**: Watch Dijkstra's, Bellman-Ford, or A* find the shortest path- **🎯 Visual Path Finding**: Watch Dijkstra's, Bellman-Ford, or A* find the shortest path



## How to Use- **🎨 Real-time Visualization**: See nodes being explored (green) and the final path (red)- **🎨 Real-time Visualization**: See nodes being explored (green) and the final path (red)



1. **Enter number of nodes** (e.g., 6)- **📊 Three Algorithms**: Compare Dijkstra, Bellman-Ford, and A* side-by-side- **📊 Three Algorithms**: Compare Dijkstra, Bellman-Ford, and A* side-by-side

2. **Add edges** in format: `from_node to_node weight`

   - Example: `0 1 5.0`- **⚡ Simple & User-Friendly**: No complex commands, just click and explore!- **⚡ Simple & User-Friendly**: No complex commands, just click and explore!

   - Enter `-1 -1 -1` when done

3. **Select source and target nodes**

4. **Choose algorithm** (1=Dijkstra, 2=Bellman-Ford, 3=A*, 4=Compare All)

## 🚀 Quick Start## 🚀 Quick Start

The program will show:

- ✅ Shortest path found

- 📏 Total path cost

- 👣 Nodes visited### Install & Build### Install & Build

- ⚡ Execution time

- 🛣️ Complete path with highlighted edges```bash```bash



## Quick Demo# Install SFML library# Install SFML library



```bashsudo apt-get update && sudo apt-get install -y libsfml-devsudo apt-get update && sudo apt-get install -y libsfml-dev

./run_demo.sh

```



## Example# Build the project# Build the project



```mkdir build && cd buildmkdir build && cd build

How many nodes? 4

Edge 1: 0 1 10cmake ..cmake ..

Edge 2: 0 2 5

Edge 3: 1 3 2make -jmake -j

Edge 4: 2 3 7

Edge 5: -1 -1 -1``````

Source: 0

Target: 3

Algorithm: 1

### Run Interactive Mode (Default)### Run Interactive Mode (Default)

Result: 0 → 1 → 3 (cost: 12)

``````bash```bash



## Algorithms./shortest_path./shortest_path



- **Dijkstra**: Best for non-negative weights - O((V+E) log V)``````

- **Bellman-Ford**: Handles negative weights - O(V×E)

- **A\***: Uses position heuristic - O(E) best case



---**Then follow the on-screen instructions:****Then follow the on-screen instructions:**

**Author**: Krishna Kumar

1. **Click** anywhere to add nodes1. **Click** anywhere to add nodes

2. Press **'E'** then click 2 nodes to connect them (enter weight)2. Press **'E'** then click 2 nodes to connect them (enter weight)

3. Press **'S'** then click a node to set it as SOURCE (blue)3. Press **'S'** then click a node to set it as SOURCE (blue)

4. Press **'T'** then click a node to set it as TARGET (magenta)4. Press **'T'** then click a node to set it as TARGET (magenta)

5. Press **SPACEBAR** to run the algorithm and watch it find the shortest path!5. Press **SPACEBAR** to run the algorithm and watch it find the shortest path!



The shortest path will be highlighted in **RED** 🔴The shortest path will be highlighted in **RED** 🔴



### Other Modes### Other Modes



```bash```bash

# Quick demo with pre-built graph# Quick demo with pre-built graph

./shortest_path --demo./shortest_path --demo



# Performance benchmark comparison# Performance benchmark comparison

./shortest_path --benchmark./shortest_path --benchmark



# Show help# Show help

./shortest_path --help./shortest_path --help

``````



## 🎮 Controls (Interactive Mode)## 🎮 Controls (Interactive Mode)



| Key | Action || Key | Action |

|-----|--------||-----|--------|

| **Click** | Add a node || **Click** | Add a node |

| **E** | Enter edge mode (click 2 nodes to connect) || **E** | Enter edge mode (click 2 nodes to connect) |

| **S** | Select source node || **S** | Select source node |

| **T** | Select target node  || **T** | Select target node  |

| **SPACEBAR** | Run algorithm & find shortest path! || **SPACEBAR** | Run algorithm & find shortest path! |

| **R** | Reset visualization || **R** | Reset visualization |

| **C** | Clear all nodes and edges || **C** | Clear all nodes and edges |

| **N** | Return to node-adding mode || **N** | Return to node-adding mode |

| **1/2/3** | Switch algorithm (Dijkstra/Bellman-Ford/A*) || **1/2/3** | Switch algorithm (Dijkstra/Bellman-Ford/A*) |



## 🎨 Visual Legend## 🎨 Visual Legend



### Node Colors### Node Colors

- 🔵 **Blue** = Source node (starting point)- 🔵 **Blue** = Source node (starting point)

- 🟣 **Magenta** = Target node (destination)- 🟣 **Magenta** = Target node (destination)

- 🟢 **Green** = Visited during search- 🟢 **Green** = Visited during search

- 🔴 **Red** = Part of shortest path- 🔴 **Red** = Part of shortest path

- ⚪ **Gray** = Not yet visited- ⚪ **Gray** = Not yet visited



### Edge Colors### Edge Colors

- 🔴 **Red** = Part of shortest path- 🔴 **Red** = Part of shortest path

- ⚫ **Gray** = Regular edge- ⚫ **Gray** = Regular edge

- **Numbers** on edges = Weight/distance- **Numbers** on edges = Weight/distance



## 📊 Algorithm Comparison## 📊 Algorithm Comparison



| Algorithm | Best For | Time Complexity || Algorithm | Best For | Time Complexity |

|-----------|----------|----------------||-----------|----------|----------------|

| **Dijkstra** | General graphs with non-negative weights | O((V+E) log V) || **Dijkstra** | General graphs with non-negative weights | O((V+E) log V) |

| **Bellman-Ford** | Graphs with negative weights | O(V × E) || **Bellman-Ford** | Graphs with negative weights | O(V × E) |

| **A\*** | Geometric/spatial graphs | O(E) best case || **A\*** | Geometric/spatial graphs | O(E) best case |



## 📖 Example Session## 📖 Example Session



``````

╔══════════════════════════════════════════════════════════════╗╔══════════════════════════════════════════════════════════════╗

║  INTERACTIVE SHORTEST PATH VISUALIZER                       ║║  INTERACTIVE SHORTEST PATH VISUALIZER                       ║

╚══════════════════════════════════════════════════════════════╝╚══════════════════════════════════════════════════════════════╝



QUICK START:QUICK START:

  1. Click to add nodes (circles will appear)  1. Click to add nodes (circles will appear)

  2. Press 'E' then click two nodes to connect them  2. Press 'E' then click two nodes to connect them

  3. Press 'S' then click a node (it turns BLUE - Source)  3. Press 'S' then click a node (it turns BLUE - Source)

  4. Press 'T' then click a node (it turns MAGENTA - Target)  4. Press 'T' then click a node (it turns MAGENTA - Target)

  5. Press SPACEBAR to find shortest path!  5. Press SPACEBAR to find shortest path!



✓ Added Node 0✓ Added Node 0

✓ Added Node 1✓ Added Node 1

✓ Added Node 2✓ Added Node 2

→ MODE: Add Edge - Click TWO nodes to connect→ MODE: Add Edge - Click TWO nodes to connect

  First node: 0 (click second node...)  First node: 0 (click second node...)

  Second node: 1  Second node: 1

  Enter weight [or ENTER for auto-distance]: 5  Enter weight [or ENTER for auto-distance]: 5

✓ Added Edge: 0 ↔ 1 (weight: 5.0)✓ Added Edge: 0 ↔ 1 (weight: 5.0)

→ MODE: Select Source - Click a node→ MODE: Select Source - Click a node

✓ SOURCE set to Node 0 (BLUE)✓ SOURCE set to Node 0 (BLUE)

→ MODE: Select Target - Click a node→ MODE: Select Target - Click a node

✓ TARGET set to Node 2 (MAGENTA)✓ TARGET set to Node 2 (MAGENTA)



╔════════════════════════════════════════╗╔════════════════════════════════════════╗

║  FINDING SHORTEST PATH...              ║║  FINDING SHORTEST PATH...              ║

╚════════════════════════════════════════╝╚════════════════════════════════════════╝

Algorithm: Dijkstra'sAlgorithm: Dijkstra's



╔════════════════════════════════════════╗╔════════════════════════════════════════╗

║  RESULTS                               ║║  RESULTS                               ║

╚════════════════════════════════════════╝╚════════════════════════════════════════╝

  Path Cost:      12.50  Path Cost:      12.50

  Nodes Visited:  3  Nodes Visited:  3

  Time:           0.045 ms  Time:           0.045 ms

  Shortest Path:  0 → 1 → 2  Shortest Path:  0 → 1 → 2



★ Path is now shown in RED on the graph!★ Path is now shown in RED on the graph!

``````



## 🏗️ Project Structure## 🏗️ Project Structure



``````

├── CMakeLists.txt              # Build configuration├── CMakeLists.txt              # Build configuration

├── README.md                   # This file├── README.md                   # This file

├── include/├── include/

│   ├── graph.h                # Graph data structure│   ├── graph.h                # Graph data structure

│   ├── algorithms.h           # Algorithm interfaces  │   ├── algorithms.h           # Algorithm interfaces  

│   └── visualizer.h           # Interactive visualizer│   └── visualizer.h           # Interactive visualizer

└── src/└── src/

    ├── graph.cpp              # Graph implementation    ├── graph.cpp              # Graph implementation

    ├── algorithms.cpp         # Dijkstra, Bellman-Ford, A*    ├── algorithms.cpp         # Dijkstra, Bellman-Ford, A*

    ├── visualizer.cpp         # SFML interactive interface    ├── visualizer.cpp         # SFML interactive interface

    └── main.cpp               # Entry point    └── main.cpp               # Entry point

``````



## 🎓 Educational Use## 🎓 Educational Use



This tool is perfect for:This tool is perfect for:

- **Learning** how shortest path algorithms work- **Learning** how shortest path algorithms work

- **Visualizing** the step-by-step execution- **Visualizing** the step-by-step execution

- **Comparing** different algorithm strategies- **Comparing** different algorithm strategies

- **Understanding** graph theory concepts- **Understanding** graph theory concepts

- **Teaching** computer science courses- **Teaching** computer science courses



## 💡 Tips## 💡 Tips



- Start with a small graph (5-6 nodes) to understand the algorithm- Start with a small graph (5-6 nodes) to understand the algorithm

- Try different graph layouts to see how algorithms behave- Try different graph layouts to see how algorithms behave

- Use auto-distance (press ENTER) for quick edge creation- Use auto-distance (press ENTER) for quick edge creation

- Watch the green nodes to see the exploration order- Watch the green nodes to see the exploration order

- Red path shows the final shortest route!- Red path shows the final shortest route!



## 📝 License## 📝 License



MIT License - Free for educational and personal useMIT License - Free for educational and personal use



## 👨‍💻 Author## 👨‍💻 Author



Krishna KumarKrishna Kumar



------



**Enjoy exploring shortest path algorithms visually!** 🎉**Enjoy exploring shortest path algorithms visually!** 🎉


## Features

- **Three Algorithm Implementations:**
  - **Dijkstra's Algorithm**: Optimal for graphs with non-negative weights
  - **Bellman-Ford Algorithm**: Handles negative weights, explores all paths
  - **A* Algorithm**: Uses Euclidean heuristic for faster pathfinding

- **Interactive Visualization:**
  - Real-time node exploration highlighting (green = visited)
  - Dynamic edge relaxation updates (yellow = relaxed)
  - Final shortest path display (red = path)
  - Source (blue) and target (magenta) nodes clearly marked
  - Live statistics: nodes visited, path cost, execution time

- **Performance Benchmarking:**
  - Side-by-side comparison of all three algorithms
  - Metrics: execution time, path cost, nodes visited
  - Identifies fastest and most efficient algorithm

- **Graph Generation:**
  - Random geometric graph generator
  - Adjustable node count and connection radius
  - Euclidean distance-based edge weights

## Requirements

- C++17 or later
- CMake 3.10+
- SFML 2.5+

## Installation

### Ubuntu/Debian
```bash
sudo apt-get update
sudo apt-get install -y libsfml-dev cmake g++
```

### Build
```bash
mkdir build && cd build
cmake ..
make -j
```

## Usage

### Basic Usage (Dijkstra visualization)
```bash
./shortest_path
```

### Benchmark All Algorithms
```bash
./shortest_path --benchmark
```

### Run Specific Algorithm
```bash
./shortest_path --algorithm dijkstra   # Dijkstra's algorithm
./shortest_path --algorithm bellman    # Bellman-Ford algorithm
./shortest_path --algorithm astar      # A* algorithm
./shortest_path --algorithm all        # Run all three sequentially
```

### Custom Graph Parameters
```bash
./shortest_path --nodes 50 --radius 250 --source 0 --target 49
```

### All Options
```bash
./shortest_path --nodes 40 --radius 180 --source 5 --target 35 --algorithm astar
```

## Command Line Options

| Option | Description | Default |
|--------|-------------|---------|
| `--nodes <n>` | Number of nodes in graph | 30 |
| `--radius <r>` | Connection radius for edge creation | 200.0 |
| `--source <s>` | Source node ID | 0 |
| `--target <t>` | Target node ID | n-1 |
| `--algorithm <alg>` | Algorithm: dijkstra, bellman, astar, all | dijkstra |
| `--benchmark` | Run performance comparison only | false |
| `--help` | Show help message | - |

## Visualization Guide

### Node Colors
- **Blue**: Source node
- **Magenta**: Target node
- **Green**: Visited nodes during exploration
- **Red**: Nodes in final shortest path
- **Gray**: Unvisited nodes

### Edge Colors
- **Red**: Edges in final shortest path
- **Yellow**: Relaxed edges (distance updated)
- **Gray**: Regular edges

## Algorithm Comparison

### Dijkstra's Algorithm
- **Time Complexity**: O((V + E) log V) with binary heap
- **Best For**: Non-negative weighted graphs
- **Advantage**: Efficient and optimal for most cases

### Bellman-Ford Algorithm
- **Time Complexity**: O(V × E)
- **Best For**: Graphs with negative weights, detecting negative cycles
- **Advantage**: More versatile, handles negative weights

### A* Algorithm
- **Time Complexity**: O(E) in best case, O(b^d) in worst case
- **Best For**: Geometric graphs with good heuristics
- **Advantage**: Often explores fewer nodes than Dijkstra

## Example Output

```
========== PERFORMANCE COMPARISON ==========

Graph: 30 nodes
Source: 0, Target: 29

Algorithm           Time (ms)      Path Cost      Nodes Visited  
-----------------------------------------------------------------
Dijkstra            0.156          847.23         18             
Bellman-Ford        0.892          847.23         30             
A*                  0.112          847.23         12             
-----------------------------------------------------------------

Analysis:
  Fastest: A*
  Most Efficient (fewest nodes): A*
```

## Project Structure

```
.
├── CMakeLists.txt          # Build configuration
├── README.md               # This file
├── include/
│   ├── graph.h            # Graph data structure
│   ├── algorithms.h       # Algorithm declarations
│   └── visualizer.h       # Visualization interface
└── src/
    ├── graph.cpp          # Graph implementation
    ├── algorithms.cpp     # Algorithm implementations
    ├── visualizer.cpp     # SFML visualization
    └── main.cpp           # Entry point
```

## Implementation Details

- **Graph Representation**: Adjacency list for efficient neighbor iteration
- **Data Structures**: Priority queue (min-heap) for Dijkstra and A*
- **Heuristic**: Euclidean distance for A* algorithm
- **Visualization**: Multi-threaded to keep UI responsive during algorithm execution
- **Thread Safety**: Mutex-protected state updates for real-time visualization

## License

MIT License - Feel free to use and modify for educational purposes.

## Author

Krishna Kumar
