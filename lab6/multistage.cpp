#include <iostream>
#include <vector>
#include <climits>
using namespace std;
const int INF = INT_MAX;

// Structure to represent a vertex in the graph
struct Vertex {
    int weight;
    vector<int> edges;
};

// Function to find the shortest path in a DAG using dynamic programming
int shortestPathDAG(const vector<vector<Vertex>>& graph) {
    int n = graph.size(); // Number of vertices in the graph

    // Create a DP table to store the shortest distances
    vector<int> dp(n, INF);

    // Base case: the shortest distance to the source vertex is 0
    dp[0] = 0;

    // Perform dynamic programming to compute shortest paths
    for (int u = 0; u < n; ++u) {
        for (int v : graph[u][0].edges) {
            // Relaxation step: update shortest distance if a shorter path is found
            if (dp[u] != INF && dp[u] + graph[u][0].weight < dp[v]) {
                dp[v] = dp[u] + graph[u][0].weight;
            }
        }
    }

    // Return the shortest distance to the destination vertex
    return dp[n - 1];
}
int main() {
    
    vector<vector<Vertex>> graph = {
        {{0, {1, 2}}, {}}, // Vertex 0: Source
        {{5, {2}}, {}},   // Vertex 1
        {{2, {3, 4}}, {}},// Vertex 2
        {{0, {}}},        // Vertex 3: Destination
    };

    int shortestDist = shortestPathDAG(graph);
    if (shortestDist != INF) {
        cout << "Shortest distance from source to destination: " << shortestDist << endl;
    } else {
        cout << "No path from source to destination exists!" << endl;
    }
    return 0;
}

