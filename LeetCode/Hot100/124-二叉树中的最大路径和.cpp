#include <iostream>

using namespace std;


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 思路采用根须便利，自下而上，计算当前节点的最大路径和主要对比：
// 带上当前节点的情况：
// 左侧max + 右侧max + 自己
// 左侧max + 自己
// 右侧max + 自己
// 不带上当前节点的情况：
// max = 0
// 更新全局max

// 100% - 51.13%
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        // 边界：
        if(root == nullptr) return 0;
    
        maxPathDown(root);

        return max_result;

    }

private:
    int max_result=INT_MIN;

    int maxPathDown(TreeNode* node){
        if(node == nullptr) return 0;
        
        // 左侧：
        int max_left = maxPathDown(node->left);
        max_left = max_left > 0 ? max_left : 0;

        // 右侧：
        int max_right = maxPathDown(node->right);
        max_right = max_right > 0 ? max_right : 0;

        // 当前：
        int max_curr = max_right + max_left + node->val;

        // 全局：
        max_result = max_result > max_curr ? max_result : max_curr;

        // 选边：
        return node->val + (max_left > max_right ? max_left : max_right);

    }

};