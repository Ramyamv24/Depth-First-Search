#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;


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
public:
    int maxSum = INT_MIN;

    int maxGain(TreeNode* node) {
        if (node == nullptr)
            return 0;

        int left = max(0, maxGain(node->left));
        int right = max(0, maxGain(node->right));

        maxSum = max(maxSum, node->val + left + right);

        return node->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        maxGain(root);
        return maxSum;
    }
};

int main() {
    

    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution obj;
    cout << "Maximum Path Sum: " << obj.maxPathSum(root) << endl;

    // Free memory
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}