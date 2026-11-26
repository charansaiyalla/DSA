// LC - 987 
// Vertical Order Traversal of a Binary Tree

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        vector<tuple<int, int, int>> nodes;

        function<void(TreeNode*, int, int)> dfs =
        [&](TreeNode* node, int row, int col) {

            if (node == nullptr)
                return;

            nodes.push_back({col, row, node->val});

            dfs(node->left, row + 1, col - 1);

            dfs(node->right, row + 1, col + 1);
        };

        dfs(root, 0, 0);

        sort(nodes.begin(), nodes.end());

        vector<vector<int>> ans;

        int prev = INT_MIN;

        for (auto &[col, row, val] : nodes) {

            if (col != prev) {
                ans.push_back({});
                prev = col;
            }

            ans.back().push_back(val);
        }

        return ans;
    }
};

int main() {

    /*
              3
             / \
            9   20
               /  \
              15   7
    */

    // Create binary tree
    TreeNode* root = new TreeNode(3);

    root->left = new TreeNode(9);

    root->right = new TreeNode(20);

    root->right->left = new TreeNode(15);

    root->right->right = new TreeNode(7);

    Solution obj;

    vector<vector<int>> result = obj.verticalTraversal(root);

    cout << "Vertical Order Traversal:" << endl;

    for (auto &column : result) {

        cout << "[ ";

        for (int val : column) {
            cout << val << " ";
        }

        cout << "] ";
    }

    cout << endl;

    function<void(TreeNode*)> deleteTree = [&](TreeNode* node) {

        if (node == nullptr)
            return;

        deleteTree(node->left);
        deleteTree(node->right);

        delete node;
    };

    deleteTree(root);

    return 0;
}