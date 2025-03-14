class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        
        // Edge cases
        if (n == 1) return cost[0];
        if (n == 2) return min(cost[0], cost[1]);
        
        // dp[i] represents the minimum cost to reach the i-th step
        vector<int> dp(n + 1, 0);
        
        // Base cases: we can start from either step 0 or step 1
        dp[0] = 0;  // Starting point, no cost
        dp[1] = 0;  // Alternative starting point, no cost
        
        // Fill dp array
        for (int i = 2; i <= n; i++) {
            // To reach step i, we can come from either step i-1 or step i-2
            // We need to pay the cost of the step we're coming from
            dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]);
        }
        
        // Return the minimum cost to reach the top (beyond the last step)
        return dp[n];
    }
};
