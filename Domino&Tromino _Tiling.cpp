class Solution {
public:
    int numTilings(int n) {
        const int MOD = 1e9 + 7;
        
        // Handle base cases
        if (n == 1) return 1;
        if (n == 2) return 2;
        
        // dp[i][0]: number of ways to fully tile a 2×i board
        // dp[i][1]: number of ways to tile a 2×i board with top-right cell uncovered
        // dp[i][2]: number of ways to tile a 2×i board with bottom-right cell uncovered
        vector<vector<long long>> dp(n + 1, vector<long long>(3, 0));
        
        // Initialize base cases
        dp[1][0] = 1; // One vertical domino
        dp[1][1] = 0; // Can't have a valid tiling with just top cell covered
        dp[1][2] = 0; // Can't have a valid tiling with just bottom cell covered
        
        dp[2][0] = 2; // Two vertical dominos or two horizontal dominos
        dp[2][1] = 1; // One tromino with top-right cell uncovered
        dp[2][2] = 1; // One tromino with bottom-right cell uncovered
        
        for (int i = 3; i <= n; i++) {
            // Full tiling of 2×i board can be achieved by:
            // 1. Full tiling of 2×(i-1) board + vertical domino
            // 2. Full tiling of 2×(i-2) board + two horizontal dominos
            // 3. Partial tiling with top uncovered at i-1 + tromino
            // 4. Partial tiling with bottom uncovered at i-1 + tromino
            dp[i][0] = (dp[i-1][0] + dp[i-2][0] + dp[i-1][1] + dp[i-1][2]) % MOD;
            
            // Partial tiling with top-right cell uncovered can be achieved by:
            // 1. Partial tiling with bottom uncovered at i-1 + horizontal domino
            dp[i][1] = (dp[i-1][2] + dp[i-2][0]) % MOD;
            
            // Partial tiling with bottom-right cell uncovered can be achieved by:
            // 1. Partial tiling with top uncovered at i-1 + horizontal domino
            dp[i][2] = (dp[i-1][1] + dp[i-2][0]) % MOD;
        }
        
        return dp[n][0];
    }
};

