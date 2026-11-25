// LC - 110
// Balanced Binary Tree

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

// Definition for a binary tree node
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
    int height(TreeNode* root) {
        if (!root)
            return 0;

        int leftH = height(root->left);
        int rightH = height(root->right);

        return 1 + max(leftH, rightH);
    }

    bool isBalanced(TreeNode* root) {
        if (root == nullptr)
            return true;

        int leftH = height(root->left);
        int rightH = height(root->right);

        if (abs(leftH - rightH) > 1)
            return false;

        return isBalanced(root->left) &&
               isBalanced(root->right);
    }
};

int main() {

    /*
             1
            / \
           2   3
          / \
         4   5
    */

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution obj;

    if (obj.isBalanced(root)) {
        cout << "Binary Tree is Balanced" << endl;
    }
    else {
        cout << "Binary Tree is NOT Balanced" << endl;
    }

    return 0;
}