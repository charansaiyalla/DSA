// LC - 545
// Boundary of Binary Tree

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

    bool isLeaf(TreeNode* root) {
        return (root->left == nullptr && root->right == nullptr);
    }

    void addLeftBoundary(TreeNode* root, vector<int>& ans) {

        TreeNode* curr = root->left;

        while(curr != nullptr) {

            if(!isLeaf(curr))
                ans.push_back(curr->val);

            if(curr->left != nullptr)
                curr = curr->left;
            else
                curr = curr->right;
        }
    }

    void addLeaves(TreeNode* root, vector<int>& ans) {

        if(isLeaf(root)) {
            ans.push_back(root->val);
            return;
        }

        if(root->left != nullptr)
            addLeaves(root->left, ans);

        if(root->right != nullptr)
            addLeaves(root->right, ans);
    }

    void addRightBoundary(TreeNode* root, vector<int>& ans) {

        TreeNode* curr = root->right;

        vector<int> temp;

        while(curr != nullptr) {

            if(!isLeaf(curr))
                temp.push_back(curr->val);

            if(curr->right != nullptr)
                curr = curr->right;
            else
                curr = curr->left;
        }

        for(int i = temp.size() - 1; i >= 0; i--) {
            ans.push_back(temp[i]);
        }
    }

    vector<int> boundaryTraversal(TreeNode* root) {

        vector<int> ans;

        if(root == nullptr)
            return ans;

        if(!isLeaf(root))
            ans.push_back(root->val);

        addLeftBoundary(root, ans);

        addLeaves(root, ans);

        addRightBoundary(root, ans);

        return ans;
    }
};

int main() {

    // Creating the binary tree
    //
    //              1
    //             / \
    //            2   3
    //           / \   \
    //          4   5   7
    //             / \
    //            8   9

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->left->right->left = new TreeNode(8);
    root->left->right->right = new TreeNode(9);

    root->right->right = new TreeNode(7);

    Solution obj;

    vector<int> result = obj.boundaryTraversal(root);

    cout << "Boundary Traversal: ";

    for(int x : result) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}