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

// // 错了，这个时AVL树
// class Solution {
// public:
//     bool isValidBST(TreeNode* root) {
//         dfs(root);
//         return is_avl;
//     }
//
// private:
//     int is_avl = true;
//     int dfs(TreeNode* root) {
//         if (root == nullptr || is_avl) return 0;
//
//         int left_depth = dfs(root->left);
//         int right_depth = dfs(root->right);
//         int curr_depth = left_depth > right_depth ? left_depth + 1 : right_depth + 1;
//         int balance = left_depth - right_depth;
//         if (balance > 1 || balance < -1) is_avl = false;
//
//         return curr_depth;
//     }
// };

// 100%, 18.13%
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        long prev = LONG_MIN;
        return inorder(root, prev);

    }
private:
    bool inorder(TreeNode* root, long& prev) {
        if (root == nullptr) return true;

        if (!inorder(root->left,prev)) return false;

        if (root->val <= prev) return false;
        prev = root->val;

        return inorder(root->right,prev);
    }
};