class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        // Handle edge cases
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        
        // dp[i] represents the maximum amount that can be robbed up to the ith house
        vector<int> dp(n, 0);
        
        // Base cases
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        
        // Fill dp array
        for (int i = 2; i < n; i++) {
            // Either rob the current house and add the money from i-2 houses
            // Or skip the current house and keep the money from i-1 houses
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }
        
        // Return the maximum amount that can be robbed
        return dp[n-1];
    }
};
