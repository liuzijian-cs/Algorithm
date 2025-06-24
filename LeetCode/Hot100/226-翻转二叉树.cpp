#include <ios>

#include <bits/ios_base.h>

//
// Created by alpha on 2025/6/24.
//
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 100% - 38.96%
// dfs
class Solution {
public:
    TreeNode *invertTree(TreeNode *root) {
        if (root == nullptr) return root;

        TreeNode *left_tree = invertTree(root->left);
        TreeNode *right_tree = invertTree(root->right);

        // swap:
        root->left = right_tree;
        root->right = left_tree;

        return root;
    }
};

// bfs:100% - 17.09%
#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
    TreeNode *invertTree(TreeNode *root) {
        if (root == nullptr) return root;

        queue<TreeNode *> queue;

        queue.push(root);

        while (!queue.empty()) {
            TreeNode *node = queue.front();
            queue.pop();

            // swap:
            TreeNode *temp = node->left;
            node->left = node->right;
            node->right = temp;

            if (node->left!=nullptr) queue.push(node->left);
            if (node->right!=nullptr) queue.push(node->right);
        }


        return root;
    }
};
