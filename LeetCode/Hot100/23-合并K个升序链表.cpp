//
// Created by alpha on 2025/8/4.
//

// 思路：有一点区间合并的思想，始终维护每一个列表的最小值
// 比如：1-[1,4,5],1-[1,3,4],1-[2,6]
// 持续选择最小值


//Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

    }
};