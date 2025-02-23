#include <iostream>
using namespace std;

// Definition of a tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

// Function to find the height of the binary tree
int findHeight(Node* root) {
    if (root == nullptr) {
        return -1; // Return -1 if height is defined as the number of edges, 0 for number of nodes.
    }
    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);
    
    return max(leftHeight, rightHeight) + 1;
}

// Helper function to insert nodes in the tree
Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}

int main() {
    Node* root = nullptr;

    // Constructing the tree
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 12);
    root = insert(root, 18);

    cout << "Height of the binary tree: " << findHeight(root) << endl;
    
    return 0;
}
