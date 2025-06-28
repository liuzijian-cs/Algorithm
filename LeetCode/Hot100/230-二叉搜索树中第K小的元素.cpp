//
// Created by alpha on 2025/6/28.
//
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//100% -70.54%
class Solution {
public:
    int kthSmallest(TreeNode *root, int k) {
        depth = k;
        int v;
        inorder(root,v);
        return v;
    }

private:
    int depth = 0;

    void inorder(TreeNode *root, int &v) {
        if (root == nullptr) { return;}


        inorder(root->left, v);

        depth --;
        if (depth == 0) {
            v = root->val;
            return;
        }

        inorder(root->right, v);
    }
};
