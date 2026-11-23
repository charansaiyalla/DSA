// LC - 103
// Binary Tree Zigzag Level Order Traversal

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        if(root == nullptr)
            return ans;

        queue<TreeNode*> q;
        q.push(root);

        bool flag = true;

        while(!q.empty()) {
            int size = q.size();
            vector<int> temp(size);

            for(int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                int pos = flag ? i : size - i - 1;
                temp[pos] = node->val;

                if(node->left != nullptr)
                    q.push(node->left);

                if(node->right != nullptr)
                    q.push(node->right);
            }

            ans.push_back(temp);
            flag = !flag;
        }

        return ans;
    }
};

int main() {

    // Creating the binary tree
    //
    //              3
    //             / \
    //            9   20
    //               /  \
    //              15   7

    TreeNode* root = new TreeNode(3);

    root->left = new TreeNode(9);
    root->right = new TreeNode(20);

    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution obj;

    vector<vector<int>> result = obj.zigzagLevelOrder(root);

    cout << "Zigzag Level Order Traversal:" << endl;

    for(int i = 0; i < result.size(); i++) {
        cout << "Level " << i + 1 << ": ";

        for(int x : result[i]) {
            cout << x << " ";
        }

        cout << endl;
    }

    return 0;
}