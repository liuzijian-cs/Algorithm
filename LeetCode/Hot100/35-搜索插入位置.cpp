//
// Created by alpha on 2025/6/23.
//

#include <iostream>
#include <vector>
using namespace std;

// 100%-55.44%
class Solution {
public:
    int searchInsert(vector<int> &nums, int target) {
        auto it = std::lower_bound(nums.begin(), nums.end(), target);
        return it - nums.begin();
    }
};


// 100%-98.93%
class Solution {
public:
    int searchInsert(vector<int> &nums, int target) {
        if (nums.empty()) return 0;

        int left = 0, right = nums.size();

        // 1 3 5 6 <= 3
        // 0 1 2 3
        // l m   r
        // lm r
        //

        // l m   r
        //   l m r
        //   lr
        // return l = 1

        // 1 3 5 6 <= 5
        // 0 1 2 3
        // l m   r
        //   l m r
        //     lm r

        while (left < right) {
            int mid = left + (right - left) / 2;
            // 这里向下取整，所以m愿意往左去(即使在碰到相同值的情况下，那么正确位置应该在m右，所以是left=mid+1)
            if (target > nums[mid]) left = mid + 1;
            else right = mid;
        }
        return left;
    }
};
