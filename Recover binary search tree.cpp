#include <iostream>
using namespace std;

/**
 * Definition for a binary tree node.
 */
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
    TreeNode* prev = NULL;
    TreeNode* first = NULL;
    TreeNode* middle = NULL;
    TreeNode* last = NULL;

    void in(TreeNode* root)
    {
        if (root == NULL)
            return;

        in(root->left);

        if (prev != NULL && prev->val > root->val)
        {
            if (first == NULL)
            {
                first = prev;
                middle = root;
            }
            else
            {
                last = root;
            }
        }

        prev = root;

        in(root->right);
    }

    void recoverTree(TreeNode* root)
    {
        in(root);

        if (last == NULL)
            swap(first->val, middle->val);
        else
            swap(first->val, last->val);
    }
};

// Inorder traversal for printing
void printInorder(TreeNode* root)
{
    if (root == NULL)
        return;

    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main()
{
    /*
        Construct the swapped BST

              3
             / \
            1   4
               /
              2

        Nodes 2 and 3 are swapped.
    */

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(2);

    cout << "Inorder before recovery: ";
    printInorder(root);
    cout << endl;

    Solution obj;
    obj.recoverTree(root);

    cout << "Inorder after recovery: ";
    printInorder(root);
    cout << endl;

    return 0;
}