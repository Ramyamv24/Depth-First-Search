#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base case
        if (root == nullptr || root == p || root == q) {
            return root;
        }

        // Search in left and right subtrees
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // If both sides return non-null, current node is LCA
        if (left != nullptr && right != nullptr) {
            return root;
        }

        // Otherwise return whichever side is non-null
        return (left != nullptr) ? left : right;
    }
};

int main() {
    

    TreeNode* root = new TreeNode(3);

    root->left = new TreeNode(5);
    root->right = new TreeNode(1);

    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);

    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);

    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    Solution obj;

    // Test Case 1
    TreeNode* p = root->left;          // Node 5
    TreeNode* q = root->right;         // Node 1

    TreeNode* ans = obj.lowestCommonAncestor(root, p, q);

    cout << "LCA of " << p->val << " and " << q->val
         << " is " << ans->val << endl;

    // Test Case 2
    p = root->left;                    // Node 5
    q = root->left->right->right;      // Node 4

    ans = obj.lowestCommonAncestor(root, p, q);

    cout << "LCA of " << p->val << " and " << q->val
         << " is " << ans->val << endl;

    // Test Case 3
    p = root->left->right->left;       // Node 7
    q = root->left->right->right;      // Node 4

    ans = obj.lowestCommonAncestor(root, p, q);

    cout << "LCA of " << p->val << " and " << q->val
         << " is " << ans->val << endl;

    return 0;
}