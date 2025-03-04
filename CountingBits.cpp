//Counting Bits
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n + 1, 0);
        int offset = 1; // Most recent power of two

        for (int i = 1; i <= n; i++) {
            if (offset * 2 == i) {
                offset = i; // Update offset when reaching a new power of two
            }
            dp[i] = dp[i - offset] + 1; // Use previously computed results
        }

        return dp;
    }
};
