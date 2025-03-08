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
    int goodNodes(TreeNode* root) {
        // Start DFS from root with initial max value as root's value
        return dfs(root, INT_MIN);
    }
    
private:
    int dfs(TreeNode* node, int maxSoFar) {
        // Base case: empty node
        if (!node) return 0;
        
        // Count current node as good if its value >= maxSoFar
        int count = (node->val >= maxSoFar) ? 1 : 0;
        
        // Update maxSoFar to max of current value and previous max
        int newMax = max(maxSoFar, node->val);
        
        // Recursively count good nodes in left and right subtrees
        count += dfs(node->left, newMax);
        count += dfs(node->right, newMax);
        
        return count;
    }
};
