//Merge two 2D arrays by summing values

#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        // Map to store id -> value
        map<int, int> idToValue;
        
        // Process nums1
        for (const auto& pair : nums1) {
            int id = pair[0];
            int value = pair[1];
            idToValue[id] = value;
        }
        
        // Process nums2 and add values for common ids
        for (const auto& pair : nums2) {
            int id = pair[0];
            int value = pair[1];
            
            if (idToValue.find(id) != idToValue.end()) {
                // ID exists in nums1, add the value
                idToValue[id] += value;
            } else {
                // ID does not exist in nums1, add new entry
                idToValue[id] = value;
            }
        }
        
        // Convert map to result vector
        vector<vector<int>> result;
        for (const auto& [id, value] : idToValue) {
            result.push_back({id, value});
        }
        
        return result;
    }
};