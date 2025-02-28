#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, 
                               vector<vector<string>>& queries) {
        // Build the graph
        unordered_map<string, unordered_map<string, double>> graph;
        
        for (int i = 0; i < equations.size(); i++) {
            string A = equations[i][0];
            string B = equations[i][1];
            double value = values[i];
            
            graph[A][B] = value;
            graph[B][A] = 1.0 / value;
        }
        
        // Process queries
        vector<double> results;
        
        for (const auto& query : queries) {
            string C = query[0];
            string D = query[1];
            
            // Check if variables exist in graph
            if (graph.find(C) == graph.end() || graph.find(D) == graph.end()) {
                results.push_back(-1.0);
                continue;
            }
            
            // Special case: C and D are the same variable
            if (C == D) {
                results.push_back(1.0);
                continue;
            }
            
            // BFS to find path from C to D
            unordered_set<string> visited;
            queue<pair<string, double>> q;
            bool found = false;
            
            q.push({C, 1.0});
            visited.insert(C);
            
            while (!q.empty() && !found) {
                auto [node, value] = q.front();
                q.pop();
                
                for (const auto& [neighbor, weight] : graph[node]) {
                    if (visited.find(neighbor) == visited.end()) {
                        double newValue = value * weight;
                        
                        if (neighbor == D) {
                            results.push_back(newValue);
                            found = true;
                            break;
                        }
                        
                        visited.insert(neighbor);
                        q.push({neighbor, newValue});
                    }
                }
            }
            
            if (!found) {
                results.push_back(-1.0);
            }
        }
        
        return results;
    }
};