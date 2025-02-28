//Shortest Common Supersequence

class Solution {
    public:
        string shortestCommonSupersequence(string str1, string str2) {
            int m = str1.length();
            int n = str2.length();
            
            // Build LCS (Longest Common Subsequence) table
            vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
            
            for (int i = 1; i <= m; i++) {
                for (int j = 1; j <= n; j++) {
                    if (str1[i - 1] == str2[j - 1]) {
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                    } else {
                        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                    }
                }
            }
            
            // Construct the shortest common supersequence
            string result = "";
            int i = m, j = n;
            
            while (i > 0 && j > 0) {
                if (str1[i - 1] == str2[j - 1]) {
                    // If current characters are same, add once
                    result = str1[i - 1] + result;
                    i--; j--;
                } else if (dp[i - 1][j] > dp[i][j - 1]) {
                    // If str1's character contributes to LCS
                    result = str1[i - 1] + result;
                    i--;
                } else {
                    // If str2's character contributes to LCS
                    result = str2[j - 1] + result;
                    j--;
                }
            }
            
            // Add remaining characters from str1
            while (i > 0) {
                result = str1[i - 1] + result;
                i--;
            }
            
            // Add remaining characters from str2
            while (j > 0) {
                result = str2[j - 1] + result;
                j--;
            }
            
            return result;
        }
    };