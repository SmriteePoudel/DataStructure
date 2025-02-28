//Leaf-Similar Trees

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
        bool leafSimilar(TreeNode* root1, TreeNode* root2) {
            // Collect leaf values from both trees
            vector<int> leaves1, leaves2;
            collectLeaves(root1, leaves1);
            collectLeaves(root2, leaves2);
            
            // Compare leaf sequences
            return leaves1 == leaves2;
        }
        
    private:
        void collectLeaves(TreeNode* root, vector<int>& leaves) {
            if (!root) return;
            
            // If it's a leaf node, add its value to our sequence
            if (!root->left && !root->right) {
                leaves.push_back(root->val);
                return;
            }
            
            // Recursively collect leaves from left to right
            collectLeaves(root->left, leaves);
            collectLeaves(root->right, leaves);
        }
    };