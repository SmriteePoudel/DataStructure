/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        if (!root) return 0;
        
        // Use a hashmap to store prefix sums and their frequencies
        unordered_map<long long, int> prefixSums;
        // Empty path (needed for paths that start from root)
        prefixSums[0] = 1;
        
        return countPaths(root, 0, targetSum, prefixSums);
    }
    
private:
    int countPaths(TreeNode* node, long long currentSum, int targetSum, unordered_map<long long, int>& prefixSums) {
        if (!node) return 0;
        
        // Update the current sum
        currentSum += node->val;
        
        // Number of paths ending at current node
        int numPaths = prefixSums[currentSum - targetSum];
        
        // Add current sum to prefix sums
        prefixSums[currentSum]++;
        
        // Recursively check left and right subtrees
        int leftPaths = countPaths(node->left, currentSum, targetSum, prefixSums);
        int rightPaths = countPaths(node->right, currentSum, targetSum, prefixSums);
        
        // Backtrack: remove current sum from prefix sums to not affect parallel paths
        prefixSums[currentSum]--;
        
        return numPaths + leftPaths + rightPaths;
    }
};
