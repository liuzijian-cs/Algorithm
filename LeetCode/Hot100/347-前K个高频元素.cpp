//
// Created by Admin on 2025/8/6.
//

// 思路：
// 用大根对维护一个pair（数字-出现的次数）然后按照出现的次数从大到小排序？
#include <iostream>
#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

// 解析：
// 1. 统计每个元素的频率（使用哈希表）
// 2. 使用小根堆维护前K个高频元素
// 3. 遍历频率表，如果堆大小小于K就直接加入，否则与堆顶比较

// 100% - 87.43%
class Solution {
public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        // Step 1: 统计每一个元素的频率
        unordered_map<int, int> hashmap;
        for (int num: nums) hashmap[num]++;

        // Step 2: 使用小根堆维护前K个高频元素
        // 下沉条件
        auto compare = [](const pair<int, int> a, const pair<int,int> b) {
            return a.second > b.second;
        };

        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(compare)> minHeap(compare);

        // Step 3: 遍历频率表，维护大小为K的小根堆
        for (const auto& item:hashmap) {
            if (minHeap.size()<k) minHeap.push({item.first, item.second});
            else if (item.second > minHeap.top().second) {
                minHeap.pop();
                minHeap.push({item.first, item.second});
            }
        }

        // 第四步：从堆中提取结果
        vector<int> result;
        result.reserve(k);

        while (!minHeap.empty()) {
            result.push_back(minHeap.top().first);
            minHeap.pop();
        }

        return result;
    }
};
