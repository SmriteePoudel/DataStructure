//Unique Number of Occurrences

class Solution {
    public:
        bool uniqueOccurrences(vector<int>& arr) {
            // Use a hash map to count occurrences of each number
            unordered_map<int, int> countMap;
            
            // Count occurrences of each number
            for (int num : arr) {
                countMap[num]++;
            }
            
            // Use a set to check if occurrence counts are unique
            unordered_set<int> uniqueCounts;
            
            // Check each occurrence count
            for (auto& pair : countMap) {
                // If this count is already in the set, return false
                if (uniqueCounts.count(pair.second) > 0) {
                    return false;
                }
                // Add the count to the set
                uniqueCounts.insert(pair.second);
            }
            
            // All occurrence counts are unique
            return true;
        }
    };