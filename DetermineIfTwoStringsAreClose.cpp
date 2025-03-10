#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <set>

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        // Check if the lengths are the same
        if (word1.length() != word2.length()) {
            return false;
        }
        
        // Count character frequencies in both words
        std::unordered_map<char, int> freq1;
        std::unordered_map<char, int> freq2;
        std::set<char> chars1;
        std::set<char> chars2;
        
        for (char c : word1) {
            freq1[c]++;
            chars1.insert(c);
        }
        
        for (char c : word2) {
            freq2[c]++;
            chars2.insert(c);
        }
        
        // Check if the set of characters is the same
        if (chars1 != chars2) {
            return false;
        }
        
        // Check if the frequency distributions match
        std::vector<int> freqList1;
        std::vector<int> freqList2;
        
        for (const auto& pair : freq1) {
            freqList1.push_back(pair.second);
        }
        
        for (const auto& pair : freq2) {
            freqList2.push_back(pair.second);
        }
        
        // Sort frequencies to check if they match after potential rearrangement
        std::sort(freqList1.begin(), freqList1.end());
        std::sort(freqList2.begin(), freqList2.end());
        
        return freqList1 == freqList2;
    }
};
