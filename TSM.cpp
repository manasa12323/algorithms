#include <iostream>
#include <climits>
using namespace std;

#define V 4   // Number of cities

int minCost = INT_MAX;

// Function to calculate minimum travelling cost
void tsp(int graph[V][V], bool visited[], int currPos, int count, int cost, int start) {
    
    // If all cities visited and return to start
    if (count == V && graph[currPos][start]) {
        minCost = min(minCost, cost + graph[currPos][start]);
        return;
    }

    // Try visiting unvisited cities
    for (int i = 0; i < V; i++) {
        if (!visited[i] && graph[currPos][i]) {
            visited[i] = true;
            tsp(graph, visited, i, count + 1, cost + graph[currPos][i], start);
            visited[i] = false;  // Backtrack
        }
    }
}

int main() {
    int graph[V][V] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    bool visited[V] = {false};

    visited[0] = true;  // Start from city 0
    tsp(graph, visited, 0, 1, 0, 0);

    cout << "Minimum travelling cost: " << minCost << endl;

    return 0;
}