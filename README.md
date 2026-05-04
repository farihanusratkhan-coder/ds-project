#✈️ Airplane Route Planner (C++)
📌 Overview

This project is a simple airplane route planning system developed in C++. It uses data structures and graph algorithms to find the most efficient route between different airports.

##⚙️ Features
Find shortest path between two airports
Graph-based representation of flight routes
Efficient route calculation using algorithms like Dijkstra
User-friendly console-based interaction
##🧠 Concepts Used
Graph (Adjacency List/Matrix)
Dijkstra’s Algorithm
Priority Queue / Heap
Basic Data Structures (Arrays, Vectors, etc.)

##🚀 How It Works
Airports are treated as nodes and routes between them as edges with weights (distance/cost). The system calculates the optimal path based on these weights.

##🖥️ Sample Output
--- Current Airline Route Map ---
SIN (Singapore) -> LHR (10800km)
JFK (New York) -> No outgoing flights
LHR (London) -> JFK (5500km)
DXB (Dubai) -> LHR (5500km) DAC (3500km) JFK (11000km)
DAC (Dhaka) -> DXB (3500km) SIN (2900km)

--- Shortest Route Summary ---
Path: DAC (Dhaka) -> DXB (Dubai) -> LHR (London)
Total Distance: 9000 km

##🛠️ Technologies
Language: C++
Concepts: Data Structures & Algorithms
##▶️ How to Run
Compile the code using any C++ compiler (e.g., g++)
Run the executable file
Input source and destination airports
Get the best possible route
##📊 Future Improvements
Add GUI for better visualization
Include real-time data (cost, time, weather)
Support for multiple route comparisons
