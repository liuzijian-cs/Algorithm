//
// Created by alpha on 2025/6/27.
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;


// 26.77% - 21.81%
class Solution {
public:
    int findKthLargest(vector<int> &nums, int k) {
        auto cmp = [](int a, int b) { return a > b; }; // greater 下沉，a > b 所以 a 下沉

        priority_queue<int, vector<int>, decltype(cmp)> min_heap(cmp);

        for (int i = 0; i < nums.size(); i++) {
            min_heap.push(nums[i]);
            if (i>=k) min_heap.pop();
        }
        return min_heap.top();
    }
};
