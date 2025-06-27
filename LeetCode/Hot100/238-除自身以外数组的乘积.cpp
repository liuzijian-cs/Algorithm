//
// Created by alpha on 2025/6/27.
//

// 没思路

#include <iostream>
#include <vector>
using namespace std;

// 最优解法是左右乘积法 (Left-Right Product Method)：
// 第一次遍历：计算每个位置左边所有元素的乘积 (First pass: calculate the product of all elements to the left of each
// position) 第二次遍历：计算每个位置右边所有元素的乘积，// 并与左边乘积相乘

// 1  2  3  4
// 1  1  2  6
// 19.85% - 90%
class Solution {
public:
    vector<int> productExceptSelf(vector<int> &nums) {
        vector<int> result(nums.size(), 1);
        // left:
        for (int i = 1; i < nums.size(); i++) result[i] = result[i - 1] * nums[i - 1];

        // right:
        int product = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            result[i] = product * result[i];
            product *= nums[i];
        }
        return result;
    }
};
