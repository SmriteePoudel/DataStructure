//Routting Oranges

#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        queue<pair<int, int>> rottenQueue;
        int freshCount = 0;
        
        // Initialize the queue with all rotten oranges and count fresh oranges
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    rottenQueue.push({i, j});
                } else if (grid[i][j] == 1) {
                    freshCount++;
                }
            }
        }
        
        // If there are no fresh oranges, return 0
        if (freshCount == 0) return 0;
        
        // Directions: up, right, down, left
        vector<pair<int, int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        
        int minutes = 0;
        
        // BFS to rot oranges
        while (!rottenQueue.empty() && freshCount > 0) {
            int size = rottenQueue.size();
            
            // Process all rotten oranges at the current minute
            for (int i = 0; i < size; i++) {
                auto [row, col] = rottenQueue.front();
                rottenQueue.pop();
                
                // Check all 4 directions
                for (auto [dr, dc] : directions) {
                    int newRow = row + dr;
                    int newCol = col + dc;
                    
                    // Check if the adjacent cell is within bounds and has a fresh orange
                    if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && grid[newRow][newCol] == 1) {
                        // Make the orange rotten
                        grid[newRow][newCol] = 2;
                        rottenQueue.push({newRow, newCol});
                        freshCount--;
                    }
                }
            }
            
            minutes++;
        }
        
        // If there are still fresh oranges left, it's impossible to rot all oranges
        return freshCount > 0 ? -1 : minutes;
    }
};