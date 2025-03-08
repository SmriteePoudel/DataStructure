#include <vector>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            // If mid element is less than its right neighbor,
            // then a peak must exist on the right side
            if (nums[mid] < nums[mid + 1]) {
                left = mid + 1;
            } 
            // Otherwise, a peak must exist on the left side or at mid
            else {
                right = mid;
            }
        }
        
        // When left == right, we've found a peak element
        return left;
    }
};
