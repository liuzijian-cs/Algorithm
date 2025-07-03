//
// Created by alpha on 2025/7/3.
//

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// 由于约束条件很严格，我们可以使用 Floyd 循环检测算法（也称为龟兔赛跑算法）。
// 使用快慢指针找到环中的相遇点
// 将其中一个指针重置到起点，两个指针以相同速度移动

// 62.82% - 86.45%
// 80.70% - 68.39%
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (fast == slow) break;
        }
        fast = nums[0];
        while (fast != slow) {
            fast = nums[fast];
            slow = nums[slow];
        }
        return fast;
    }
};

// |------a---|--b--|
//            |     |
//            |-----|



// 超时
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast = 0;
        int slow = 0;
        while (true) {
            fast = (fast+2)%nums.size();
            slow = (fast+1)%nums.size();
            if (nums[fast] == nums[slow]) break;
        }
        return nums[fast];
    }
};