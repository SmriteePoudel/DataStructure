class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        // Flatten the grid into a single vector
        vector<int> nums;
        for (const auto& row : grid) {
            nums.insert(nums.end(), row.begin(), row.end());
        }
        
        // Sort the vector
        sort(nums.begin(), nums.end());
        
        // Check if making a uni-value grid is possible
        for (int i = 1; i < nums.size(); i++) {
            if ((nums[i] - nums[0]) % x != 0) {
                return -1;
            }
        }
        
        // Find the median
        int median = nums[nums.size() / 2];
        
        // Calculate total operations
        int totalOperations = 0;
        for (int num : nums) {
            totalOperations += abs(num - median) / x;
        }
        
        return totalOperations;
    }
};
