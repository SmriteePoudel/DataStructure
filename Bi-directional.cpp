#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // Build adjacency list
        vector<vector<pair<int, long long>>> graph(n);
        for (auto& road : roads) {
            int u = road[0], v = road[1], time = road[2];
            graph[u].push_back({v, time});
            graph[v].push_back({u, time}); // bi-directional roads
        }
        
        const int MOD = 1e9 + 7;
        
        // Distances array to store shortest distance from source to each node
        vector<long long> dist(n, LLONG_MAX);
        dist[0] = 0;
        
        // Ways array to store number of ways to reach each node with shortest distance
        vector<long long> ways(n, 0);
        ways[0] = 1;
        
        // Min-heap priority queue for Dijkstra's algorithm
        // Pair of {distance, node}
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        pq.push({0, 0}); // Starting from source node 0
        
        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();
            
            // If this distance is greater than the current best distance, skip
            if (d > dist[node]) continue;
            
            // Visit all neighbors
            for (auto& [neighbor, time] : graph[node]) {
                // If we found a shorter path to the neighbor
                if (dist[node] + time < dist[neighbor]) {
                    dist[neighbor] = dist[node] + time;
                    ways[neighbor] = ways[node]; // Reset count
                    pq.push({dist[neighbor], neighbor});
                } 
                // If we found another path with the same shortest distance
                else if (dist[node] + time == dist[neighbor]) {
                    ways[neighbor] = (ways[neighbor] + ways[node]) % MOD;
                }
            }
        }
        
        return ways[n-1];
    }
};
