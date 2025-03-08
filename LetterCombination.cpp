#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        // Handle empty input case
        if (digits.empty()) {
            return {};
        }
        
        // Define the mapping of digits to letters
        vector<string> phoneMap = {
            "",     // 0
            "",     // 1
            "abc",  // 2
            "def",  // 3
            "ghi",  // 4
            "jkl",  // 5
            "mno",  // 6
            "pqrs", // 7
            "tuv",  // 8
            "wxyz"  // 9
        };
        
        vector<string> result;
        string currentCombination = "";
        
        // Start the backtracking
        backtrack(result, phoneMap, digits, 0, currentCombination);
        
        return result;
    }
    
private:
    void backtrack(vector<string>& result, const vector<string>& phoneMap, 
                   const string& digits, int index, string& currentCombination) {
        // If we've processed all digits, add the current combination to the result
        if (index == digits.length()) {
            result.push_back(currentCombination);
            return;
        }
        
        // Get the current digit and the corresponding letters
        int digit = digits[index] - '0';
        const string& letters = phoneMap[digit];
        
        // Try each letter for the current digit
        for (char letter : letters) {
            // Add the current letter to the combination
            currentCombination.push_back(letter);
            
            // Recurse to the next digit
            backtrack(result, phoneMap, digits, index + 1, currentCombination);
            
            // Backtrack (remove the last added letter)
            currentCombination.pop_back();
        }
    }
};
