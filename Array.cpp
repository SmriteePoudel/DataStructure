//partition array according to given pivot

#include <vector>

class Solution {
public:
    std::vector<int> pivotArray(std::vector<int>& nums, int pivot) {
        std::vector<int> less;     // Elements less than pivot
        std::vector<int> equal;    // Elements equal to pivot
        std::vector<int> greater;  // Elements greater than pivot
        
        // Partition the elements into three groups
        for (int num : nums) {
            if (num < pivot) {
                less.push_back(num);
            } else if (num == pivot) {
                equal.push_back(num);
            } else {
                greater.push_back(num);
            }
        }
        
        // Combine the three groups in the required order
        std::vector<int> result;
        
        // Add all elements less than pivot
        for (int num : less) {
            result.push_back(num);
        }
        
        // Add all elements equal to pivot
        for (int num : equal) {
            result.push_back(num);
        }
        
        // Add all elements greater than pivot
        for (int num : greater) {
            result.push_back(num);
        }
        
        return result;
    }
};