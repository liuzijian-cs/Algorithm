//
// Created by alpha on 2025/7/3.
//
#include <iostream>
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

// 思路：dfs
// 递归出口：root == nullptr &&
// 用target表达当前需要的值，但是对于每一个路径，都可以不要之前的节点，这里该如何思考？

// 分析：这道题目的核心难点在于理解"路径可以从任意节点开始"。
// 路径必须向下（从父节点到子节点）
// 路径可以从任意节点开始，不一定是根节点
// 路径可以在任意节点结束，不一定是叶子节点

// 对于每个节点，我们需要考虑两种情况：
// 包含当前节点的路径数量
// 不包含当前节点，但在其子树中的路径数量

// =====过程理解：
// 让我们把这个难点具体化：
// 如果我们只考虑以A为起点的路径，那么我们只需要计算 A, A->B, A->B->C 的和。
// 但题目要求路径可以从任意节点开始。这意味着，在遍历到C时，我们不仅要考虑 A->B->C，还要考虑 B->C 和 C 本身。

// 我们暂不考虑将每一个节点作为递归起点的方法

// 前缀和 + 哈希表 (高效且优雅的方法)
// 这是对方法一的巨大优化。它避免了重复计算，将时间复杂度降到了 O(N)、
// 核心思想：
// 当我们从根节点一路向下走到某个节点 C 时，我们记录了从根节点 A 到 C 的路径和，我们称之为 currentSum。
// 现在，我们想知道，在这条 A -> ... -> B -> ... -> C 的路径上，是否存在一个子路径（比如从 B 到 C）的和恰好为
// targetSum？ 从根到B的路径和 = currentSum - targetSum 这就把问题转化为了： 当我在节点 C，计算出了当前的路径和
// currentSum 后，我需要回头看看，在我之前的路径上，是否存在一个前缀和，它恰好等于 currentSum - targetSum？
// 如果存在，那么从那个节点之后到我当前这个节点的子路径，和就是 targetSum。
// 哈希表的作用（如何高效地“回头看”？）：Key (long long) : 一个前缀和的值。Value (int) :
// 这个前缀和在当前路径上出现了多少次。 算法流程（DFS）： 我们用一个 dfs 函数，从根节点开始遍历，同时维护 currentSum 和
// prefixSumCount。


// 当前节点的路径和 = preSum[currentSum - targetSum]，即在当前路径上存在多少个前缀点，它们的前缀和为(currentSum -
// targetSum)，表示从该点到当前节点的路径和是targetSum。
//
// 比如：
//
// A: 当前前缀和a
// 到B: 前缀和a+b
// 到C: 前缀和a+b+c
// 如果前面在路径上有某一点的前缀和为S，那么S+targetSum=currentSum，说明从S+1那个节点一直到当前节点的这一段路径和就是targetSum。
//
// 以“B+C”为例说明：
// 让我们用targetSum举例：
//
// 到B节点：前缀和是a+b
// 到C节点：前缀和是a+b+c
// 计算B+C相加为targetSum的路径，其实就是在C节点时，查找是否有前缀和等于currentSum - targetSum（即a+b+c -
// targetSum）的节点。 假如targetSum == b+c（想找从B开始加C的路径） currentSum 到达C节点时是a+b+c
// 查找preSum里是不是有前缀和 a （"A"节点到根的路径），如果有，说明从A下一个，也就是B开始，到C这段的和为targetSum
// 更通用地说
// 路径等于“currentSum（当前点） - oldSum（某个前面点） == targetSum”。
// 因此只要在到达C前，模式里面把到每个点的前缀和出现次数都统计了，就能在任何到达C时，用currentSum-targetSum去查找，看有多少preSum[
// currentSum - targetSum ]。 每一个这样的oldSum实际上就是起点，可以实现从A、从B、从C单独求起始的所有向下的路径。


// 67.69% - 22.62%
class Solution {
public:
    int pathSum(TreeNode *root, int targetSum) {
        // 前缀和哈希表，记录从根节点到当前节点的路径上各个前缀和的出现次数
        unordered_map<long long, int> prefix_sum_count;

        // 初始化：空路径的前缀和为0，出现1次
        prefix_sum_count[0] = 1;

        return dfs(root, 0, targetSum, prefix_sum_count);
    }

private:
    int dfs(TreeNode *root, long long current_sum, int target_sum, unordered_map<long long, int> &prefix_sum_count) {
        if (root == nullptr) return 0; // 递归出口：空节点

        // 更新当前路径和
        current_sum += root->val;

        // 查找是否存在前缀和，使得 currentSum - prefixSum = targetSum
        int path_count = prefix_sum_count[current_sum - target_sum];

        // 将当前前缀和加入哈希表
        prefix_sum_count[current_sum] += 1;

        path_count += dfs(root->left, current_sum, target_sum, prefix_sum_count);
        path_count += dfs(root->right, current_sum, target_sum, prefix_sum_count);

        // 手动回溯
        prefix_sum_count[current_sum] -= 1;

        return path_count;
    }
};
