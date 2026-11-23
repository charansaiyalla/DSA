// LC - 102
// Binary Tree Level Order Traversal

#include <bits/stdc++.h>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        if(root == NULL)
            return ans;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int size = q.size();
            vector<int> temp;

            for(int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                temp.push_back(node->val);

                if(node->left != NULL)
                    q.push(node->left);

                if(node->right != NULL)
                    q.push(node->right);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};

int main() {

    // Creating the binary tree
    //
    //          3
    //         / \
    //        9   20
    //           /  \
    //          15   7

    TreeNode* root = new TreeNode(3);

    root->left = new TreeNode(9);
    root->right = new TreeNode(20);

    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution obj;

    vector<vector<int>> result = obj.levelOrder(root);

    cout << "Level Order Traversal:" << endl;

    for(int i = 0; i < result.size(); i++) {
        cout << "Level " << i + 1 << ": ";

        for(int x : result[i]) {
            cout << x << " ";
        }

        cout << endl;
    }

    return 0;
}