#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        // Handle empty input case
        if (strs.empty()) {
            return "";
        }
        
        // Start with the first string as our initial prefix
        std::string prefix = strs[0];
        
        // Check this prefix against all other strings
        for (int i = 1; i < strs.size(); i++) {
            // Shrink the prefix until it matches the current string
            while (strs[i].substr(0, prefix.length()) != prefix) {
                prefix = prefix.substr(0, prefix.length() - 1);
                
                // If prefix becomes empty, there's no common prefix
                if (prefix.empty()) {
                    return "";
                }
            }
        }
        
        return prefix;
    }
};

// Alternative implementation using character-by-character comparison
class Solution2 {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        // Handle empty input case
        if (strs.empty()) {
            return "";
        }
        
        // Find the shortest string length
        int minLen = strs[0].length();
        for (const auto& str : strs) {
            minLen = std::min(minLen, static_cast<int>(str.length()));
        }
        
        // Compare character by character
        for (int i = 0; i < minLen; i++) {
            char curr = strs[0][i];
            for (int j = 1; j < strs.size(); j++) {
                if (strs[j][i] != curr) {
                    return strs[0].substr(0, i);
                }
            }
        }
        
        // If we get here, the common prefix is the shortest string
        return strs[0].substr(0, minLen);
    }
};

// Simple test function
void testLongestCommonPrefix() {
    Solution sol;
    
    // Test case 1: ["flower","flow","flight"]
    std::vector<std::string> test1 = {"flower", "flow", "flight"};
    std::cout << "Test 1: " << sol.longestCommonPrefix(test1) << std::endl; // Should output "fl"
    
    // Test case 2: ["dog","racecar","car"]
    std::vector<std::string> test2 = {"dog", "racecar", "car"};
    std::cout << "Test 2: " << sol.longestCommonPrefix(test2) << std::endl; // Should output ""
    
    // Additional test case: empty array
    std::vector<std::string> test3 = {};
    std::cout << "Test 3: " << sol.longestCommonPrefix(test3) << std::endl; // Should output ""
    
    // Additional test case: single string
    std::vector<std::string> test4 = {"alone"};
    std::cout << "Test 4: " << sol.longestCommonPrefix(test4) << std::endl; // Should output "alone"
}
