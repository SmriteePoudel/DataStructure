#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size();
        int n = grid[0].size();
        int k = queries.size();
        
        // Directions for moving up, down, left, and right
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        // Sort queries and keep track of their original indices
        vector<pair<int, int>> sorted_queries;
        for (int i = 0; i < k; ++i) {
            sorted_queries.emplace_back(queries[i], i);
        }
        sort(sorted_queries.begin(), sorted_queries.end());
        
        // Min-heap to store cells with their values and coordinates
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> min_heap;
        min_heap.emplace(grid[0][0], 0, 0);
        
        // Visited matrix
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        visited[0][0] = true;
        
        // Result map to store the maximum points for each query value
        unordered_map<int, int> result_map;
        int points = 0;
        
        // Process each query
        for (const auto& [query_value, original_index] : sorted_queries) {
            // Expand the BFS frontier while the top of the heap has a value less than the query value
            while (!min_heap.empty() && get<0>(min_heap.top()) < query_value) {
                auto [value, x, y] = min_heap.top();
                min_heap.pop();
                ++points;
                
                // Explore the four possible directions
                for (const auto& [dx, dy] : directions) {
                    int nx = x + dx;
                    int ny = y + dy;
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny]) {
                        visited[nx][ny] = true;
                        min_heap.emplace(grid[nx][ny], nx, ny);
                    }
                }
            }
            result_map[query_value] = points;
        }
        
        // Construct the answer array based on the original queries
        vector<int> answer(k);
        for (int i = 0; i < k; ++i) {
            answer[i] = result_map[queries[i]];
        }
        
        return answer;
    }
};
