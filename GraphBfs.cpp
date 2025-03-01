//Nearest Exit from Entrance in Maze

#include <vector>
#include <queue>
#include <utility>

class Solution {
public:
    int nearestExit(std::vector<std::vector<char>>& maze, std::vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();
        
        // Define the four possible movement directions: up, right, down, left
        std::vector<std::pair<int, int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        
        // Create a queue for BFS
        std::queue<std::pair<int, int>> q;
        
        // Mark the entrance as visited by changing it to a wall
        int startRow = entrance[0];
        int startCol = entrance[1];
        maze[startRow][startCol] = '+';
        
        // Add the entrance to the queue with distance 0
        q.push({startRow, startCol});
        
        // Distance from entrance
        int steps = 0;
        
        // BFS
        while (!q.empty()) {
            int size = q.size();
            
            // Process all cells at the current distance
            for (int i = 0; i < size; i++) {
                auto [row, col] = q.front();
                q.pop();
                
                // Try all four directions
                for (const auto& dir : directions) {
                    int newRow = row + dir.first;
                    int newCol = col + dir.second;
                    
                    // Check if new position is within bounds and is an empty cell
                    if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && maze[newRow][newCol] == '.') {
                        // Check if it's an exit
                        if (newRow == 0 || newRow == m - 1 || newCol == 0 || newCol == n - 1) {
                            return steps + 1;  // Found an exit
                        }
                        
                        // Mark as visited and add to queue
                        maze[newRow][newCol] = '+';
                        q.push({newRow, newCol});
                    }
                }
            }
            
            // Increment steps for the next level
            steps++;
        }
        
        // No exit found
        return -1;
    }
};