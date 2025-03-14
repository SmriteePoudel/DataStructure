#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // O(n) solution
    int maximumCount(vector<int>& nums) {
        int neg = 0, pos = 0;
        
        for (int num : nums) {
            if (num < 0) neg++;
            else if (num > 0) pos++;
        }
        
        return max(neg, pos);
    }
    
    // O(log n) solution for follow-up
    int maximumCountOptimized(vector<int>& nums) {
        // Find the position of the first non-negative number
        int firstNonNeg = lower_bound(nums.begin(), nums.end(), 0) - nums.begin();
        
        // Find the position of the first positive number
        int firstPos = lower_bound(nums.begin(), nums.end(), 1) - nums.begin();
        
        int neg = firstNonNeg; // Count of negative numbers
        int pos = nums.size() - firstPos; // Count of positive numbers
        
        return max(neg, pos);
    }
};
Esmrity is typing
Esmrity is typing
