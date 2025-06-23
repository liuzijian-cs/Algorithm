//
// Created by alpha on 2025/6/23.
//

#include <iostream>
#include <vector>
using namespace std;

// 贪心策略：
// maxReach / nextReach / result；

class Solution {
public:
    int jump(vector<int> &nums) {
        if (nums.size() <= 1) return 0;

        int result = 0;

        int maxReach = 0, nextReach = 0;

        for (int i = 0; i < nums.size() - 1; i++) {

            // 下一次Jump的最远距离
            nextReach = max(nextReach, i + nums[i]);

            if (i == maxReach) {
                result++;
                maxReach = nextReach;
                if (maxReach >= nums.size() - 1) return result;
            }
        }
        return -1;
    }
};
