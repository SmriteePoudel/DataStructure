#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        // Define the search space
        int left = 1;  // Minimum possible value given the constraints
        int right = 1e9;  // Maximum possible value given the constraints
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            // Check if we can rob at least k houses with capability = mid
            if (canRob(nums, k, mid)) {
                // If possible, try to minimize the capability
                right = mid;
            } else {
                // If not possible, increase the capability
                left = mid + 1;
            }
        }
        
        return left;
    }
    
private:
    // Check if it's possible to rob at least k houses with given capability
    bool canRob(const vector<int>& nums, int k, int capability) {
        int count = 0;  // Number of houses robbed
        int i = 0;
        
        while (i < nums.size()) {
            // If the current house can be robbed with the given capability
            if (nums[i] <= capability) {
                count++;  // Rob this house
                i += 2;   // Skip the adjacent house
            } else {
                i++;      // Skip this house
            }
        }
        
        return count >= k;
    }
};