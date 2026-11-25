// LC - 543
// Diameter of Binary Tree

#include <iostream>
#include <algorithm>
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
    int height(TreeNode* root, int& dia) {
        if (!root)
            return 0;

        int lh = height(root->left, dia);
        int rh = height(root->right, dia);

        dia = max(dia, lh + rh);

        return 1 + max(lh, rh);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int dia = 0;
        height(root, dia);
        return dia;
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

    int result = obj.diameterOfBinaryTree(root);

    cout << "Diameter of Binary Tree: " << result << endl;

    return 0;
}