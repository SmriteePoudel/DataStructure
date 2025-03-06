//Reorder Routes to Make All Paaths Lead to the City Zero

#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        // Create adjacency list for the graph
        vector<vector<pair<int, bool>>> graph(n);
        
        // Build the graph: pair.first is the connected city, pair.second indicates if it's original direction
        // true = original direction (needs to be reversed if traversing this edge), false = reversed direction
        for (const auto& conn : connections) {
            int from = conn[0], to = conn[1];
            graph[from].push_back({to, true});     // Original direction
            graph[to].push_back({from, false});    // Reversed direction
        }
        
        // BFS starting from city 0
        queue<int> q;
        vector<bool> visited(n, false);
        
        q.push(0);
        visited[0] = true;
        
        int count = 0;
        
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            
            // Process all neighbors
            for (const auto& [neighbor, isOriginal] : graph[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                    
                    // If edge is in original direction (pointing away from city 0),
                    // we need to reverse it
                    if (isOriginal) {
                        count++;
                    }
                }
            }
        }
        
        return count;
    }
};