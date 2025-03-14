#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        // If we have a very large k value, we might not be able to distribute any candy
        long long totalCandies = 0;
        for (int candy : candies) {
            totalCandies += candy;
        }
        
        // If total candies are less than number of children, return 0
        if (totalCandies < k) return 0;
        
        // Binary search for the maximum candies each child can get
        int left = 1;  // Minimum possible (each gets at least 1)
        int right = *max_element(candies.begin(), candies.end());  // Maximum possible
        
        while (left < right) {
            int mid = left + (right - left + 1) / 2;  // Taking ceiling to avoid infinite loop
            
            // Check if we can distribute 'mid' candies to each child
            if (canDistribute(candies, k, mid)) {
                left = mid;  // Try for more candies per child
            } else {
                right = mid - 1;  // Try with fewer candies per child
            }
        }
        
        return left;
    }
    
private:
    // Helper function to check if we can distribute 'candiesPerChild' to 'k' children
    bool canDistribute(vector<int>& candies, long long k, int candiesPerChild) {
        long long childrenCount = 0;
        
        for (int pile : candies) {
            // Number of children who can get 'candiesPerChild' from current pile
            childrenCount += pile / candiesPerChild;
            
            // If we've already found enough sub-piles for all children, return true
            if (childrenCount >= k) {
                return true;
            }
        }
        
        // Couldn't distribute to all k children
        return false;
    }
};
