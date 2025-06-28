//
// Created by alpha on 2025/6/28.
//

// 分析：
// 这道题的核心思想是利用分治法来构建平衡二叉搜索树：
// 关键观察 / Key Observation: 有序数组的中间元素作为根节点，可以保证左右子树的节点数量尽可能平衡
// 递归策略 / Recursive Strategy: 将数组分为三部分：左半部分、中间元素、右半部分
// 平衡性保证 / Balance Guarantee: 每次选择中点作为根节点，确保树的高度最小

// 算法思路：
// 其中元素已经按 升序 排列，请你将其转换为一棵
// 选择数组中点作为当前子树的根节点
// 递归构建左子树（使用左半数组）
// 递归构建右子树（使用右半数组）
// 边界条件：当左边界大于右边界时返回空指针

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    int height;  // AVL树需要有节点高度
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode() : val(0), height(1), left(nullptr), right(nullptr) {} // AVL树需要有节点高度


    explicit TreeNode(const int x) : val(x), left(nullptr), right(nullptr) {}
    explicit TreeNode(const int x) : val(x), height(1), left(nullptr), right(nullptr) {}

    explicit TreeNode(const int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        if (nums.empty()) return nullptr;
        return buildTree(nums, 0, nums.size());
    }

    // 新增：加入插入操作：
    TreeNode *insert(TreeNode *root, int val) {
        // Step 1: Perform standard BST insertion
        if (root == nullptr) return new TreeNode(val);

        if (val < root->val) root->left = insert(root->left, val);
        else if (val > root->val) root->right = insert(root->right, val);
        else return root; // 不允许重复，直接返回

        updateHeight(root);
        int balance = getBalanceFactor(root);

        // LL & LR
        if (balance > 1 && val < root->left->val) return rightRotate(root);
        if (balance > 1 && val > root->left->val) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
        // RL & RR
        if (balance < -1 && val > root->right->val) return leftRotate(root);
        if (balance < -1 && val < root->right->val) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

private:
    TreeNode *buildTree(vector<int> &nums, int left, int right) {
        if (left >= right) return nullptr;

        int mid = left + (right - left) / 2;

        TreeNode *root = new TreeNode(nums[mid]);

        root->left = buildTree(nums, left, mid);
        root->right = buildTree(nums, mid + 1, right);

        updateHeight(root);
        return root;
    }

    int getHeight(TreeNode *root) {
        if (root == nullptr) return 0;
        return root->height;
    }

    void updateHeight(TreeNode *root) {
        if (root == nullptr) return;
        int high_left = getHeight(root->left);
        int high_right = getHeight(root->right);
        root-> height = high_left > high_right ? high_left + 1 : high_right + 1;
    }

    int getBalanceFactor(TreeNode *root) {
        if (root == nullptr) return 0;
        return getHeight(root->left) - getHeight(root->right);
    }

    // 右旋LL情况：
    TreeNode* rightRotate(TreeNode *node) {
        TreeNode * left = node->left;
        TreeNode * left_right = left->right;

        left->right=node;
        node->left=left_right;

        // 更新高度（注意顺序：先更新y，再更新x）
        updateHeight(node);
        updateHeight(left);

        return left;
    }

    // 左：
    TreeNode* leftRotate(TreeNode *node) {
        TreeNode* right = node->right;
        TreeNode * right_left = right->left;

        right->left=node;
        node->right=right_left;

        updateHeight(node);
        updateHeight(right);

        return right;
    }
};
