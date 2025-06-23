//
// Created by alpha on 2025/6/23.
//
// 27 min : 2 methods

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Definition for a binary tree node:

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    explicit TreeNode(const int x) : val(x), left(nullptr), right(nullptr) {}

    explicit TreeNode(const int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

    // explicit 禁止类型的隐式转换：

    // struct TreeNode {
    //     int val;
    //     TreeNode *left, *right;
    //     TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    // };
    //
    // void foo(TreeNode node) { /* ... */ }
    //
    // int main() {
    //     foo(5); // 这里会把5 隐式转成 TreeNode(5)
    // }

    // struct TreeNode {
    //     int val;
    //     TreeNode *left, *right;
    //
    //     explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    // };
    //
    // void foo(TreeNode node) { /* ... */ }
    //
    // int main() {
    //     foo(5);           // 编译错误！不能隐式从 int 转 TreeNode
    //     foo(TreeNode(5)); // 这样写没问题
    // }
};

// Method 1: Recursive inorder traversal(100%-61.85%)
// Time complexity: O(n)
// Space complexity: O(h), where h is the height of tree
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        inorder(root, result);
        return result;
    }

private:
    void inorder(TreeNode *root, vector<int> &result) {
        if (root == nullptr) return;
        inorder(root->left, result);
        result.push_back(root->val);
        inorder(root->right, result);
    }
};

// Method 2: Iterative inorder traversal(100%-94.84%)
// 递归方法每进入一层递归，都会在系统调用栈上分配空间。如果二叉树很深（比如链式结构，深度上万），递归会导致栈溢出（stack
// overflow），程序崩溃。 迭代方法使用显式的栈（如
// std::stack），其大小只受限于堆内存，通常比系统调用栈大得多，更加安全可靠。
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<TreeNode *> stack; // 只保存地址
        TreeNode *current = root;

        if (root == nullptr) return result;

        // Iterate until stack is empty and current is null
        while (current != nullptr || !stack.empty()) {
            // Go left as far as possible, pushing nodes onto stack:
            while (current != nullptr) {
                stack.push(current);
                current = current->left;
            }

            // Process top of stack
            current = stack.top();
            stack.pop();
            result.push_back(current->val);

            // Move to right subtree:
            current = current->right;
        }
        return result;
    }
};
