#include <iostream>
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
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }

    int dfs(TreeNode* root, int n) {
        if (!root)
            return 0;

        n = n * 10 + root->val;

        if (!root->left && !root->right)
            return n;

        return dfs(root->left, n) + dfs(root->right, n);
    }
};

int main() {
   
     

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    Solution obj;
    cout << "Sum of Root-to-Leaf Numbers: " << obj.sumNumbers(root) << endl;

    
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}