
#include <iostream>
#include <vector>
using namespace std;
 
//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 思路：
// 递归，如果待查询节点分布在左右两边则当前节点为目标节点

// 52.25% - 89.54%
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 退出条件：节点非空或者为p或q的任意一个
        if(root==nullptr || root ==p || root ==q) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);
        
        // 如果当前节点下左右都找到了，则当前节点是
        if(left!=nullptr && right!=nullptr) return root;
        // 返回非空子树：
        return left != nullptr ? left : right;
    }
};




