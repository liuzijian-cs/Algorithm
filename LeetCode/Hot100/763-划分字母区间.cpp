//
// Created by alpha on 2025/6/25.
//

// 思路：
// 这里我感觉需要一个用一个hash map去记录，或者干脆分配一个a-z的字母表，用于记录每一个字母第一次出现和最后一次出现的位置
// 例如：a b a b c b a c a d e f e g d e
//      0 1 2 3 4 5 6 7 8 9 101112131415
// a 0 8
// b 1 5
// c 4 7
// d 9 14
// e 10 15
// g 13 13

// 然后遍历这些数组
//  比如从a开始 left=0 right=8
//  b:left=0, right=8 区间内情况
//  c:left=0, right=8 区间内情况
//  d:完全互斥 新建分组2：left=9 right =14
//  e:部分重合 left=8 right=15
//  g:区间内情况 left=8 right=15
//  最后有两组

// 感觉不是最优的解法

// 分析：
// 你的思路核心是对的：记录每个字符的最后出现位置。但是你提到的"遍历区间重合"的方法会让问题复杂化。
// 最优解法思路：

// 首先遍历字符串，记录每个字符最后出现的位置
// 再次遍历字符串，使用贪心算法：
// 维护当前片段的结束位置
// 不断更新当前片段必须到达的最远位置
// 当遍历到当前片段的结束位置时，就可以分割出一个片段
// 这是典型的贪心算法，时间复杂度O(n)，空间复杂度O(1)。

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// 29.91% - 46.58%
class Solution {
public:
    vector<int> partitionLabels(string s) {
        if (s.empty()) return vector<int>{};

        // Record last occurrence position of each character:
        unordered_map<char, int> hashmap;
        for (int i = 0; i < s.size(); i++) hashmap[s[i]] = i;

        vector<int> result;
        int start = 0;
        int end = 0;

        // Greedy algorithm: traverse sting, dynamically adjust end position of current segment
        for (int i = 0; i < s.size(); i++) {
            end = end > hashmap[s[i]] ? end : hashmap[s[i]];
            if (i == end) {
                // segment:
                result.push_back(end - start+1);
                start = i + 1;
            }
        }
        return result;
    }
};
