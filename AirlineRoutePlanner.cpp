#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <limits>

using namespace std;

// Represents a flight connection (Edge)
struct Flight {
    string destination;
    int weight; // Distance/Cost [cite: 104]
};

class FlightPlanner {
    // Adjacency List: Airports as nodes and flights as weighted edges
    unordered_map<string, list<Flight>> adjList;
    unordered_map<string, string> airportNames;

public:
    // Module 1: Build Graph - Add airports
    void addAirport(string code, string name) {
        airportNames[code] = name;
        if (adjList.find(code) == adjList.end()) {
            adjList[code] = list<Flight>();
        }
    }

    // Module 1: Build Graph - Add flights
    void addFlight(string u, string v, int weight) {
        adjList[u].push_back({v, weight});
    }

    // Module 2: Display Route Map
    void displayRouteMap() {
        cout << "\n--- Current Airline Route Map ---" << endl;
        for (auto const& pair : adjList) {
            string airport = pair.first;
            list<Flight> flights = pair.second;

            cout << airport << " (" << airportNames[airport] << ") -> ";
            if (flights.empty()) {
                cout << "No outgoing flights";
            } else {
                for (auto const& f : flights) {
                    cout << f.destination << " (" << f.weight << "km) ";
                }
            }
            cout << endl;
        }
    }

    // Module 3: Shortest Route Planner using Dijkstra's
    void findShortestRoute(string start, string end) {
        unordered_map<string, int> distances;
        unordered_map<string, string> predecessors; // For Path Reconstruction

        // Initialize distances to infinity 
        for (auto const& pair : airportNames) {
            distances[pair.first] = numeric_limits<int>::max();
            predecessors[pair.first] = "NULL"; 
        }

        distances[start] = 0;

        // Min-Priority Queue for Dijkstra
        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;
        pq.push({0, start});

        while (!pq.empty()) {
            string u = pq.top().second;
            int d = pq.top().first;
            pq.pop();

            if (d > distances[u]) continue;

            for (auto const& flight : adjList[u]) {
                if (distances[u] != numeric_limits<int>::max() && 
                    distances[u] + flight.weight < distances[flight.destination]) {
                    
                    distances[flight.destination] = distances[u] + flight.weight;
                    predecessors[flight.destination] = u;
                    pq.push({distances[flight.destination], flight.destination});
                }
            }
        }

        printSummary(start, end, distances[end], predecessors);
    }

    // Module 4 & 5: Path Reconstruction and Route Summary
    void printSummary(string start, string end, int totalDist, unordered_map<string, string>& predecessors) {
        if (totalDist == numeric_limits<int>::max()) {
            cout << "\n[!] No route found between " << start << " and " << end << endl;
            return;
        }

        vector<string> path;
        string at = end;
        while (at != "NULL") {
            path.push_back(at);
            at = predecessors[at];
        }

        reverse(path.begin(), path.end());

        cout << "\n--- Shortest Route Summary ---" << endl;
        cout << "Path: ";
        for (int i = 0; i < path.size(); i++) {
            cout << path[i] << " (" << airportNames[path[i]] << ")";
            if (i != path.size() - 1) cout << " -> ";
        }

        cout << "\nTotal Distance: " << totalDist << " km" << endl;
    }
};

int main() {
    FlightPlanner planner;

    // Build Graph
    planner.addAirport("DAC", "Dhaka");
    planner.addAirport("DXB", "Dubai");
    planner.addAirport("LHR", "London");
    planner.addAirport("JFK", "New York");
    planner.addAirport("SIN", "Singapore");

    // Add flight routes
    planner.addFlight("DAC", "DXB", 3500);
    planner.addFlight("DAC", "SIN", 2900);
    planner.addFlight("DXB", "LHR", 5500);
    planner.addFlight("DXB", "DAC", 3500);
    planner.addFlight("SIN", "LHR", 10800);
    planner.addFlight("LHR", "JFK", 5500);
    planner.addFlight("DXB", "JFK", 11000);

    // Display adjacency list [cite: 106]
    planner.displayRouteMap();

    // Find shortest route
    planner.findShortestRoute("DAC", "LHR");

    return 0;
}