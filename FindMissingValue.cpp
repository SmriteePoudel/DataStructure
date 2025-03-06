//Find Missing and Repeated Values

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int n2 = n * n;
        
        // Create a frequency array to count occurrences of each number
        vector<int> freq(n2 + 1, 0);
        
        // Count the frequency of each number in the grid
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                freq[grid[i][j]]++;
            }
        }
        
        int repeated = -1, missing = -1;
        
        // Find the repeated and missing numbers
        for (int i = 1; i <= n2; i++) {
            if (freq[i] == 2) {
                repeated = i;
            } else if (freq[i] == 0) {
                missing = i;
            }
            
            // If we've found both values, we can break early
            if (repeated != -1 && missing != -1) {
                break;
            }
        }
        
        return {repeated, missing};
    }
};