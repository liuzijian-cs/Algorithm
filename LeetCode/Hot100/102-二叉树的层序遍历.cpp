//
// Created by alpha on 2025/6/23.
//

// 27min : 1 method

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 100%-69.7%
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> result;
        if (root == nullptr) return result;

        queue<TreeNode *> queue;
        queue.push(root);
        while (!queue.empty()) {
            int levelSize = queue.size(); // 当层节点数量
            vector<int> level;

            for (int i = 0; i < levelSize; i++) {
                // Process all nodes in current level
                TreeNode * current = queue.front();
                level.push_back(current->val);
                queue.pop();

                if (current->left!=nullptr) queue.push(current->left);
                if (current-> right!=nullptr) queue.push(current->right);
            }
            result.push_back(level);
        }
        return result;
    }
};
