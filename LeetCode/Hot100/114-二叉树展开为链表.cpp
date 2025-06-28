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

#include<iostream>
#include<queue>
#include<stack>
#include<vector>
using namespace std;

// Mirror方法：100%-94.91%
class Solution {
public:
    void flatten(TreeNode* root) {

        TreeNode* curr = root;
        while (curr!=nullptr) {
            // 如果有左子树：
            if (curr->left!=nullptr) {
                // 找到左子树的最右
                TreeNode* right_child = curr->left;
                while (right_child->right!=nullptr) right_child = right_child->right;
                right_child->right = curr->right;

                curr->right = curr->left;
                curr->left = nullptr;
            }
            curr = curr->right;
        }
    }
};


// 100% - 47.22%
class Solution {
public:
    void flatten(TreeNode* root) {
        if (root==nullptr) return;

        stack<TreeNode*> stack;
        stack.push(root);

        TreeNode* prev = nullptr;

        while (!stack.empty()) {
            TreeNode* node = stack.top();
            stack.pop();

            if (prev!=nullptr) {
                prev->right = node;
                prev->left = nullptr;
            }

            if (node->right!=nullptr) stack.push(node->right);
            if (node->left!=nullptr) stack.push(node->left);

            prev = node;
        }
        if (prev!=nullptr) {prev->left = nullptr;}
    }
};