/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    public:
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            // Base case 1: If root is null, return null
            if (root == nullptr) return nullptr;
            
            // Base case 2: If root is either p or q, return root
            if (root == p || root == q) return root;
            
            // Recursively search in left and right subtrees
            TreeNode* leftSearch = lowestCommonAncestor(root->left, p, q);
            TreeNode* rightSearch = lowestCommonAncestor(root->right, p, q);
            
            // If both left and right return non-null values, root is the LCA
            if (leftSearch && rightSearch) return root;
            
            // Otherwise, return whichever is non-null
            return leftSearch ? leftSearch : rightSearch;
        }
    };