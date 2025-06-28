//
// Created by alpha on 2025/6/28.
//


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    explicit TreeNode(const int x) : val(x), left(nullptr), right(nullptr) {}

    explicit TreeNode(const int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 思路：采用递归，也就是深度遍历每一个节点（dfs），获得每一个节点的左侧和右侧的深度，返回max_left和max_right，
// 同时max = max(max_left + max_right, max)

// 你的思路基本正确！让我来分析一下：
// 正确部分：使用DFS递归遍历每个节点，计算左右子树的深度，然后用左右深度之和更新最大直径
// 需要完善的地方：需要区分"深度"和"直径"的概念，以及如何在递归过程中同时维护这两个值
// 你的思路已经是最优解法了！时间复杂度O(n)，空间复杂度O(h)，其中h是树的高度。这是一个经典的"在递归过程中维护全局状态"的问题。

#include <iostream>
#include <vector>
using namespace std;

// 100% - 91.46%
class Solution {
public:
    int diameterOfBinaryTree(TreeNode *root) {
        dfs(root);
        return max_depth;
    }

private:
    int max_depth = 0;

    int dfs(TreeNode *node) {
        if (node == nullptr) return 0;
        int left_depth = dfs(node->left);
        int right_depth = dfs(node->right);
        int curr_depth = left_depth + right_depth;
        max_depth = max_depth > curr_depth ? max_depth : curr_depth;
        return left_depth > right_depth ? left_depth + 1 : right_depth + 1;
    }
};
