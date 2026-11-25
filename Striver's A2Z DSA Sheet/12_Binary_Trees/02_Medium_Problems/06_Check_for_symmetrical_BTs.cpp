// LC - 101
// Symmetric Tree

#include <bits/stdc++.h>
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
    bool solve(TreeNode* left, TreeNode* right) {
        if (!left || !right)
            return left == right;

        if (left->val != right->val)
            return false;

        return solve(left->left, right->right) &&
               solve(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;

        return solve(root->left, root->right);
    }
};

int main() {

    /*
             1
            / \
           2   2
          / \ / \
         3  4 4  3

       Output: Symmetric
    */

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(2);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);

    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    Solution obj;

    if (obj.isSymmetric(root))
        cout << "Tree is Symmetric" << endl;
    else
        cout << "Tree is Not Symmetric" << endl;

    return 0;
}