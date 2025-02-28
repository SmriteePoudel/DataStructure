#include <vector>

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        // We'll use a two-pointer approach
        int k = 0; // Position to place the next non-val element
        
        for (int i = 0; i < nums.size(); i++) {
            // If the current element is not equal to val
            if (nums[i] != val) {
                // Move it to the position k and increment k
                nums[k] = nums[i];
                k++;
            }
            // If nums[i] == val, we skip it
        }
        
        // k now represents the number of elements not equal to val
        return k;
    }
};