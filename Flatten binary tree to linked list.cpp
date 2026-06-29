#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
    TreeNode* prev = nullptr;

public:
    void flatten(TreeNode* root) {
        if (!root)
            return;

        // Process right subtree first
        flatten(root->right);

        // Process left subtree
        flatten(root->left);

        // Rearrange pointers
        root->right = prev;
        root->left = nullptr;

        // Update previous node
        prev = root;
    }
};

// Function to print flattened tree
void printFlattened(TreeNode* root) {
    while (root != nullptr) {
        cout << root->val;
        if (root->right)
            cout << " -> ";
        root = root->right;
    }
    cout << endl;
}

int main() {
    

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(5);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);

    root->right->right = new TreeNode(6);

    Solution obj;
    obj.flatten(root);

    cout << "Flattened Tree: ";
    printFlattened(root);

    return 0;
}