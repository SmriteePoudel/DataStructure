#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
      
        vector<vector<int>> adj(n);
        vector<unordered_set<int>> adjSet(n);
        
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            adjSet[u].insert(v);
            adjSet[v].insert(u);
        }
        
        
        vector<bool> visited(n, false);
        int completeComponents = 0;
        
        
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                vector<int> component;
                dfs(i, adj, visited, component);
                
                
                if (isComplete(component, adjSet)) {
                    completeComponents++;
                }
            }
        }
        
        return completeComponents;
    }
    
private:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& component) {
        visited[node] = true;
        component.push_back(node);
        
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited, component);
            }
        }
    }
    
    bool isComplete(const vector<int>& component, const vector<unordered_set<int>>& adjSet) {
        int size = component.size();
        
       
        if (size == 1) {
            return true;
        }
        
       
        for (int node : component) {
            if (adjSet[node].size() != size - 1) {
                return false;
            }
            
            for (int other : component) {
                if (node != other && adjSet[node].find(other) == adjSet[node].end()) {
                    return false;
                }
            }
        }
        
        return true;
    }
};
