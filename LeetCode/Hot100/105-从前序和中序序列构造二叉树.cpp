//
// Created by alpha on 2025/6/28.
//

// preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
// 1           -                          -

#include <iostream>
#include <queue>
#include <unordered_map>
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

// 100% - 29.18%
class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.empty() || inorder.empty() || preorder.size() != inorder.size()) return nullptr;

        // 用哈希表加速索引查找
        unordered_map<int, int> map;
        for (int i = 0; i < inorder.size(); i++) map[inorder[i]] = i;

        return buildTree(preorder, 0, preorder.size(),inorder,0,inorder.size(),map);
    }

private:
    // 递归构造二叉树：
    TreeNode *buildTree(const vector<int> &preorder, int pre_left, int pre_right, const vector<int> &inorder,
                        int in_left, int in_right, const unordered_map<int, int> &map) {
        if (pre_left >= pre_right || in_left >= pre_right) return nullptr;

        int root_val = preorder[pre_left];

        TreeNode *root = new TreeNode(root_val);

        int index = map.at(root_val);
        int left_size = index - in_left;

        root->left = buildTree(preorder, pre_left + 1, pre_left + 1 + left_size, inorder, in_left, index, map);
        root->right = buildTree(preorder, pre_left + 1 + left_size, pre_right, inorder, index + 1, in_right, map);

        return root;
    }
};
