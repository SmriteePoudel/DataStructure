#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<std::string>> suggestedProducts(std::vector<std::string>& products, std::string searchWord) {
        // Sort the products lexicographically
        std::sort(products.begin(), products.end());
        
        std::vector<std::vector<std::string>> result;
        std::string prefix = "";
        
        for (char c : searchWord) {
            prefix += c;
            
            // Vector to store suggestions for current prefix
            std::vector<std::string> currentSuggestions;
            
            // Binary search to find the first product that has the current prefix
            auto start = std::lower_bound(products.begin(), products.end(), prefix);
            
            // Add up to 3 products that share the prefix
            for (auto it = start; it != products.end() && currentSuggestions.size() < 3; ++it) {
                // Check if the current product starts with prefix
                if (it->size() >= prefix.size() && it->substr(0, prefix.size()) == prefix) {
                    currentSuggestions.push_back(*it);
                } else {
                    // If prefix doesn't match, we can break since products are sorted
                    break;
                }
            }
            
            result.push_back(currentSuggestions);
        }
        
        return result;
    }
};
