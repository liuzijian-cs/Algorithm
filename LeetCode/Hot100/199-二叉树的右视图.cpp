//
// Created by alpha on 2025/6/28.
//

#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 思路
// 使用BFS遍历每一层
// 每层的最后一个节点就是右视图能看到的节点
// 时间复杂度: O(n)，空间复杂度: O(w) w为树的最大宽度

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

// 100%-24.26%
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;

        if (root==nullptr) return result;

        queue<TreeNode*> queue;
        queue.push(root);

        while (!queue.empty()) {
            int levelsize = queue.size();
            for (int i=0;i<levelsize;i++) {
                TreeNode* node = queue.front();
                queue.pop();

                if (i==levelsize-1) result.push_back(node->val);

                if (node->left!=nullptr) queue.push(node->left);
                if (node->right!=nullptr) queue.push(node->right);
            }
        }
        return result;
    }
};

