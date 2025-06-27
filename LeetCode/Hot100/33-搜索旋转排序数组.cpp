//
// Created by alpha on 2025/6/27.
//

// 4,5,6,7,0,1,2 left=0 right=7 mid =3 ok
// 0 1 2 3 4 5 6
// l     m       r
//         l m   r left=4 right=7 mid = 5 ok
//         l r left =4 right =5 mid = 4 accept

// 6 7 1 2 3 4 5  target = 6
// 0 1 2 3 4 5 6
// l     m       r  left=0 right=7 mid =3 右侧有序
// l m   r          left=0 right=3 mid= 1 左侧有序


// 思路：直接二分，只不过加入对左侧始终检测有序性
// 首先得到mid，然后对比 nums[0] 和 nums[mid]
// 如果 nums[0] < nums[mid] 说明左边有序，对比 nums[0] 和 target，如果 nums[0] > target 就去右边找
// 如果 nums[0] > nums[mid] 说明左边无序, 对右侧二分 left = mid + 1

// 1,3,5
// 0 1 2 3
// l m   r left=0, right=3, mid = 1


// 分析：
// 旋转数组的特点是，在任意位置二分后，必然有一侧是有序的
// 我们需要先判断哪一侧有序，然后确定目标值是否在有序的一侧
// 如果目标值在有序区间，就在有序区间搜索；否则转向另一侧继续搜索



#include <iostream>
#include <vector>
using namespace std;

// 100% - 33.67%
class Solution {
public:
    int search(vector<int> &nums, int target) {
        if (nums.empty()) return -1;

        int left = 0, right = nums.size();

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) return mid;

            // nums[left] < nums[mid] 左侧有序条件
            // nums[right] > nums[mid] 右侧有序条件

            if (nums[left] < nums[mid]) {
                //左侧有序
                if (nums[left] <= target && target<nums[mid]) right = mid;
                else left = mid + 1;
            }else {
                //右侧有序
                if (nums[mid]<target && target<=nums[right-1]) left = mid + 1;
                else right = mid;
            }
        }
        return -1;
    }
};
