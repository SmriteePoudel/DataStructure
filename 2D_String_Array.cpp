#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        // Store initial supplies in a set for O(1) lookup
        unordered_set<string> availableSupplies(supplies.begin(), supplies.end());
        
        // Build the ingredient dependency graph and count dependencies
        unordered_map<string, vector<string>> graph; // recipe -> recipes that need it
        unordered_map<string, int> inDegree; // recipe -> number of missing ingredients
        
        // Initialize in-degree counts for all recipes
        for (const auto& recipe : recipes) {
            inDegree[recipe] = 0;
        }
        
        // Build the graph and calculate in-degrees
        for (int i = 0; i < recipes.size(); i++) {
            int missingCount = 0;
            for (const auto& ingredient : ingredients[i]) {
                // If ingredient is not available and is a recipe
                if (!availableSupplies.count(ingredient)) {
                    // Add the dependency to the graph
                    graph[ingredient].push_back(recipes[i]);
                    missingCount++;
                }
            }
            inDegree[recipes[i]] = missingCount;
        }
        
        // Start topological sort with recipes that have all ingredients available
        queue<string> q;
        for (const auto& recipe : recipes) {
            if (inDegree[recipe] == 0) {
                q.push(recipe);
            }
        }
        
        vector<string> possibleRecipes;
        
        // Process the queue
        while (!q.empty()) {
            string currentRecipe = q.front();
            q.pop();
            
            // Add this recipe to our result
            possibleRecipes.push_back(currentRecipe);
            
            // Mark this recipe as available for other recipes
            availableSupplies.insert(currentRecipe);
            
            // Update recipes that depend on this one
            for (const auto& dependent : graph[currentRecipe]) {
                inDegree[dependent]--;
                if (inDegree[dependent] == 0) {
                    q.push(dependent);
                }
            }
        }
        
        return possibleRecipes;
    }
};
