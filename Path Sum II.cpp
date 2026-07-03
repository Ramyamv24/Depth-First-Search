#include <iostream>
#include <vector>
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
public:
    vector<vector<int>> answer;

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        dfs(root, targetSum, path);
        return answer;
    }

    void dfs(TreeNode* root, int newtarget, vector<int>& path) {
        if (!root)
            return;

        path.push_back(root->val);
        newtarget -= root->val;

        // If it is a leaf node
        if (!root->left && !root->right) {
            if (newtarget == 0)
                answer.push_back(path);
        } else {
            dfs(root->left, newtarget, path);
            dfs(root->right, newtarget, path);
        }

        // Backtracking
        path.pop_back();
    }
};

int main() {
    

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);

    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);

    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(1);

    int targetSum = 22;

    Solution obj;
    vector<vector<int>> result = obj.pathSum(root, targetSum);

    cout << "Paths with sum " << targetSum << ":\n";

    for (auto &path : result) {
        for (int x : path)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}