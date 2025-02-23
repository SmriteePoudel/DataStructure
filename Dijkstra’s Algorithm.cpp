
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Define a pair type (distance, vertex) for priority queue
typedef pair<int, int> pii;

// Function to implement Dijkstra's Algorithm
void dijkstra(vector<vector<pii>>& adj, int V, int src) {
    // Priority queue to store (distance, vertex), min-heap based on distance
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    // Distance array initialized to infinity (INT_MAX)
    vector<int> dist(V, INT_MAX);

    // Start with the source node
    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int currDist = pq.top().first; // Get the shortest distance
        int u = pq.top().second;       // Get the current node
        pq.pop();

        // Traverse all adjacent vertices of u
        for (auto neighbor : adj[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            // If a shorter path to v is found
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    // Print the shortest distances from the source node
    cout << "Vertex\tDistance from Source" << endl;
    for (int i = 0; i < V; i++) {
        cout << i << "\t" << (dist[i] == INT_MAX ? -1 : dist[i]) << endl;
    }
}

int main() {
    int V = 5; // Number of vertices
    vector<vector<pii>> adj(V);

    // Graph represented as an adjacency list (undirected graph)
    adj[0].push_back({1, 10});
    adj[0].push_back({4, 20});
    adj[1].push_back({2, 10});
    adj[1].push_back({3, 50});
    adj[2].push_back({3, 20});
    adj[3].push_back({4, 60});
    
    // For undirected graph, add reverse edges
    adj[1].push_back({0, 10});
    adj[4].push_back({0, 20});
    adj[2].push_back({1, 10});
    adj[3].push_back({1, 50});
    adj[3].push_back({2, 20});
    adj[4].push_back({3, 60});

    int source = 0; // Source vertex
    dijkstra(adj, V, source);

    return 0;
}
