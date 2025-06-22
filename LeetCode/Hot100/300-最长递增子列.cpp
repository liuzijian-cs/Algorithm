//
// Created by alpha on 2025/6/22.
//


#include <iostream>
#include <vector>
using namespace std;

// 动态规划个蛋

// 分析：
// 这是一个动态规划问题，
// 首先分配一个长度为n+1的dp数组，其每一个值代表这个数之前，的最大递归长度
// dp[0]=0
// 比如
//   0 3 1 6 2 2 7
// 0 0 0 0 0 0 0 0
// 0 1 0 0 0 0 0 0
// 0 1 1 0 0 0 0 0

// 状态转移应该是for从0开始到i，max(dp[i],dp[j]+1) 但这个时间复杂度好像是n2了

// 然后开始遍历整个数组

// 大体正确
// 二分查找优化解法 (Binary Search Optimized Solution)
// 时间复杂度: O(n log n) / Time Complexity: O(n log n)
// 空间复杂度: O(n) / Space Complexity: O(n)


// v3：贪心+手动二分 0ms(100%) 13.68MB(97.98%)
class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        if (nums.empty()) return 0;

        vector<int> tails;

        for (int num: nums) {
            // 二分查找
            int left = 0, right = tails.size();
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (tails[mid] < num) left = mid + 1; // right
                else right = mid;
            }

            if (left == tails.size()) tails.push_back(num);
            else tails[left] = num;

        }
        return tails.size();
    }
};

// v2：贪心+二分 0ms(100%) 13.74MB(94.7%)
class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        if (nums.empty()) return 0;

        vector<int> tails;

        for (int num: nums) {
            if (tails.empty()) tails.push_back(num); // i=0

            auto it = lower_bound(tails.begin(), tails.end(), num);
            if (it == tails.end()) tails.push_back(num);
            else *it = num;
        }
        return tails.size();
    }
};

// 贪心 + 遍历 3ms（85.24%）
class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        if (nums.empty()) return 0;

        vector<int> tails;

        for (int num: nums) {
            if (tails.empty()) tails.push_back(num); // i=0

            bool flag = false;
            for (int &tail: tails) { // 这里不是二分，需要优化
                if (tail >= num) {
                    tail = num;
                    flag = true;
                    break;
                }
            }
            if (!flag) tails.push_back(num);
        }
        return tails.size();
    }
};
