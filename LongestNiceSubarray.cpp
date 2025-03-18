class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxLength = 1;  // Minimum length is 1 as noted in the problem
        int usedBits = 0;   // Tracks which bits are used in our current window
        int left = 0;       // Left pointer of our sliding window
        
        for (int right = 0; right < n; right++) {
            // While the current number has bits that conflict with our window
            while ((usedBits & nums[right]) != 0) {
                // Remove the leftmost element from our window
                usedBits ^= nums[left];
                left++;
            }
            
            // Add the current number to our window
            usedBits |= nums[right];
            
            // Update the maximum length
            maxLength = max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
};
