//Maximim Depth of Binary Tree

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
        int maxDepth(TreeNode* root) {
            // Base case: if the root is null, the depth is 0
            if (root == nullptr) {
                return 0;
            }
            
            // Recursively calculate the depth of left and right subtrees
            int leftDepth = maxDepth(root->left);
            int rightDepth = maxDepth(root->right);
            
            // Return the maximum depth plus 1 (counting the current node)
            return max(leftDepth, rightDepth) + 1;
        }
    };