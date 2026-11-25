// LC - 124
// Binary Tree Maximum Path Sum

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
    int maxSum;

    int solve(TreeNode* root) {
        if (!root)
            return 0;

        int left = solve(root->left);
        int right = solve(root->right);

        int root_left_right = left + right + root->val;
        int root_left_or_right = max(left, right) + root->val;
        int only_root = root->val;

        maxSum = max({maxSum, root_left_right,
                      root_left_or_right, only_root});

        return max(root_left_or_right, only_root);
    }

    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        solve(root);
        return maxSum;
    }
};

int main() {
    /*
             1
            / \
           2   3

       Maximum Path Sum = 6
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    Solution obj;

    cout << "Maximum Path Sum: " << obj.maxPathSum(root) << endl;

    return 0;
}