#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        
        // Create a table to store results of subproblems
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        // Fill dp table in bottom-up fashion
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                // If first string is empty, only option is to
                // insert all characters of second string
                if (i == 0)
                    dp[i][j] = j;
                
                // If second string is empty, only option is to
                // delete all characters of first string
                else if (j == 0)
                    dp[i][j] = i;
                
                // If last characters are same, ignore last character
                // and recur for remaining string
                else if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                
                // If last characters are different, consider all
                // possibilities and find minimum
                else
                    dp[i][j] = 1 + min({dp[i][j - 1],      // Insert
                                        dp[i - 1][j],      // Delete
                                        dp[i - 1][j - 1]}); // Replace
            }
        }
        
        return dp[m][n];
    }
};
