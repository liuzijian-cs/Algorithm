//
// Created by alpha on 2025/6/11.
//

// 给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个
// 整数，并返回它们的数组下标。

#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        // 思路：
        // 遍历整个nums

        unordered_map<int, int> hashmap;  // unordered_map
        // std::map 的底层实现通常是 红黑树（Red-Black Tree，一种自平衡二叉搜索树）。
        // 每次插入、查找、删除操作，最坏情况下的时间复杂度都是 O(log n)，其中 n 是 map 中的元素个数。

        // 扩展：如果是 unordered_map 呢？
        // unordered_map 是用 哈希表 实现的。
        // 查找和插入的平均时间复杂度是 O(1)，但最坏情况下（哈希冲突多）可能退化到 O(n)。
        // .count() 在 unordered_map 里也是 O(1) 平均时间复杂度。

        // std::map 适合：
        // 需要有序存储的场合（自动按 key 排序，默认为从小到大）。
        // 需要按区间、范围操作的场合，比如 lower_bound/upper_bound（查找不小于/大于等于某个值的第一个元素）。
        // 频繁需要遍历所有元素且要有序的时候。

        // std::unordered_map 适合：
        // 只关心查找、 插入、 删除的效率，不需要有序存储的场合。
        // key 类型比较复杂但能很好 hash 的时候（比如字符串，pair等）。
        // 绝大部分“ 查找型” 题目，尤其是像“ 两数之和” 这种场景（见下文）。


        vector<int> res(2, -1); // 大小为2，值为-1

        for (int i=0; i<nums.size();i++) {
            // 需要搜索的值为 target - num, 根据这个值去整个nums中搜索
            //.count(key) 实际上是去树里查找是否存在 key，底层等价于 find(key) != end()。 所以时间复杂度是 O(log n)。
            if (hashmap.count(target-nums[i])>0) {
                res[0] = hashmap[target-nums[i]];
                res[1] = i;
                break;
            }
            hashmap[nums[i]]=i;
        }

        return res;
    }
};
