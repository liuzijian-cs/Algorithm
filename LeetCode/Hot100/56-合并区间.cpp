//
// Created by alpha on 2025/6/25.
//


// 排序 (Sorting): 首先按区间的起始位置对所有区间进行排序
// 遍历合并(Traverse and Merge) :
// 遍历排序后的区间，判断当前区间是否与前一个区间重叠 重叠判断(Overlap Detection) :
// 如果当前区间的起始位置 ≤ 前一个区间的结束位置，则重叠 合并策略(Merge Strategy) :
// 重叠时，更新前一个区间的结束位置为两个区间结束位置的最大值

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

//100%-71.25%
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        if (intervals.empty() || intervals.size() == 1) return intervals;

        sort(intervals.begin(), intervals.end(),
             [](const vector<int> &a, const vector<int> &b) { return a[0] < b[0]; });

        vector<vector<int>> result;
        result.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= result.back()[1]) {
                result.back()[1] = result.back()[1] > intervals[i][1] ? result.back()[1] : intervals[i][1];
            } else result.push_back(intervals[i]);

        }
        return result;
    }
};
