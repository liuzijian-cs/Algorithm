//
// Created by alpha on 2025/6/24.
//
#include <cmath>
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// dfs: 100% - 71.76%
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if (root == nullptr) return true;
        return isSymmetric(root->left, root->right);
    }

private:
    bool isSymmetric(TreeNode *left, TreeNode *right) {
        if (left == nullptr && right == nullptr) return true;
        if (left == nullptr || right == nullptr) return false;
        return (left->val == right->val) && isSymmetric(left->left, right->right) &&
               isSymmetric(left->right, right->left);
    }
};

// bfs:100%-28.66%
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if (root == nullptr) return true;

        // 使用队列存储需要比较的节点对 / Use queue to store pairs of nodes to compare
        queue<TreeNode *> q;
        // 为了保证对称性，因此null也入队
        q.push(root->left);
        q.push(root->right);

        while (!q.empty()) {
            TreeNode *left = q.front();
            q.pop();
            TreeNode *right = q.front();
            q.pop();

            if (left == nullptr && right == nullptr) continue;

            if (left == nullptr || right == nullptr || left->val != right->val) return false;

            q.push(left->left);
            q.push(right->right);
            q.push(left->right);
            q.push(right->left);
        }
        return true;
    }
};

class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if (root == nullptr) return true;

        queue<TreeNode *> queue;
        // queue.push(root->left);
        queue.push(root->left);
        queue.push(root->right);

        int level = 1;

        while (!queue.empty()) {
            TreeNode *left = queue.front();
            queue.pop();
            TreeNode *right = queue.front();
            queue.pop();
            // 两个都为空，继续下一对 / Both are null, symmetric, continue
            if (left == nullptr && right == nullptr) continue;

            // 一个为空或值不等，不对称 / Only one is null or values differ, not symmetric
            if (!left || !right || left->val != right->val) {
                return false;

                // 对称位置入队（左的左和右的右，左的右和右的左）/ Enqueue symmetric children
                queue.push(left->left);
                queue.push(right->right);
                queue.push(left->right);
                queue.push(right->left);

                //
                //
                // int half_range = pow(2,(level-1));
                //
                // // 入栈左侧
                // stack<TreeNode *> stack;
                //
                // for (int i=0;i<half_range;i++) {
                //     stack.push(queue.front());
                //     if (queue.front()->left!=nullptr) queue.push(queue.front()->left);
                //     if (queue.front()->right!=nullptr) queue.push(queue.front()->right);
                //     queue.pop();
                // }
                //
                // while (!stack.empty()) {
                //     if (stack.top()->val != queue.front()->val) return false;
                //     stack.pop();
                //     if (queue.front()->left!=nullptr) queue.push(queue.front()->left);
                //     if (queue.front()->right!=nullptr) queue.push(queue.front()->right);
                //     queue.pop();
            }
        }
        return true;
    }
};

// class Solution {
// public:
//     bool isSymmetric(TreeNode *root) {
//         if (root == nullptr ) return true;
//
//         queue<TreeNode *> queue;
//         // queue.push(root->left);
//         queue.push(root->left);
//         queue.push(root->right);
//
//         int level = 1;
//
//         while (!queue.empty()) {
//             TreeNode* left = queue.front(); queue.pop();
//             TreeNode* right = queue.front(); queue.pop();
//             // 两个都为空，继续下一对 / Both are null, symmetric, continue
//             if (left == nullptr && right == nullptr) continue;
//
//             // 一个为空或值不等，不对称 / Only one is null or values differ, not symmetric
//             if (!left || !right || left->val != right->val) {
//                 return false;
//
//             // 对称位置入队（左的左和右的右，左的右和右的左）/ Enqueue symmetric children
//             queue.push(left->left);
//             queue.push(right->right);
//             queue.push(left->right);
//             queue.push(right->left);
//
//             //
//             //
//             // int half_range = pow(2,(level-1));
//             //
//             // // 入栈左侧
//             // stack<TreeNode *> stack;
//             //
//             // for (int i=0;i<half_range;i++) {
//             //     stack.push(queue.front());
//             //     if (queue.front()->left!=nullptr) queue.push(queue.front()->left);
//             //     if (queue.front()->right!=nullptr) queue.push(queue.front()->right);
//             //     queue.pop();
//             // }
//             //
//             // while (!stack.empty()) {
//             //     if (stack.top()->val != queue.front()->val) return false;
//             //     stack.pop();
//             //     if (queue.front()->left!=nullptr) queue.push(queue.front()->left);
//             //     if (queue.front()->right!=nullptr) queue.push(queue.front()->right);
//             //     queue.pop();
//             }
//         }
//         return true;
//     }
// };
