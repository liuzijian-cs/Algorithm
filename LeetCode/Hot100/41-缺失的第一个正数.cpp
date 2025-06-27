//
// Created by alpha on 2025/6/27.
//


// 对于长度为n的数组，缺失的第一个正数一定在[1, n+1]范围内**
// 1   2   3   1 x5
// -1  -1  -1  1

// 我们可以将数组本身作为哈希表使用（原地哈希）

// 首先检查数组中是否包含1，如果没有1，答案就是1
// 将所有无效数字（≤0或>n）替换为1
// 遍历数组，对于每个数字，将对应位置标记为负数
// 最后找到第一个未被标记的位置

// 牛逼：原地hash
// 100% - 84.36%
class Solution {
public:
    int firstMissingPositive(vector<int> &nums) {

        // 检测是否有1如果有1直接跳过 & 处理无效数字
        bool one = false;
        for (const int num: nums)
            if (num == 1) one = true;
        if (!one) return 1;

        for (int i = 0; i < nums.size(); i++)
            if (nums[i] <= 0 || nums[i] > nums.size()) nums[i] = 1;

        for (int i = 0; i < nums.size(); i++) {
            int val = nums[i] > 0 ? nums[i] : -nums[i];
            if (nums[val - 1] > 0) nums[val - 1] = -nums[val - 1];
        }

        for (int i = 0; i < nums.size(); i++)
            if (nums[i] > 0) return i + 1;
        return nums.size()+1;
    }
};
