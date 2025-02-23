//Write a function of find height of binary tree

#include <iostream>
using namespace std;

// Definition of a Tree Node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to find the height of a binary tree
int findHeight(TreeNode* root) {
    if (root == nullptr) {
        return -1; // Return -1 if height is defined in terms of edges, 0 for nodes
    }
    
    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);
    
    return max(leftHeight, rightHeight) + 1;
}

// Example Usage
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    cout << "Height of the tree: " << findHeight(root) << endl;
    
    return 0;
}
