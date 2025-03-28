#include <vector>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        // Create a DP table of size m x n
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        // Base case: there's only one way to reach any cell in the first row or column
        for (int i = 0; i < m; i++) {
            dp[i][0] = 1;
        }
        
        for (int j = 0; j < n; j++) {
            dp[0][j] = 1;
        }
        
        // Fill the DP table
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                // Number of ways to reach current cell = sum of ways to reach from above + from left
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        
        // Return the result at bottom-right cell
        return dp[m-1][n-1];
    }
};
