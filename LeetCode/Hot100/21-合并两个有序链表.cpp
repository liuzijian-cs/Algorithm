//
// Created by alpha on 2025/6/24.
//
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    // 构造函数 / Constructor
    ListNode(int x) : val(x), next(nullptr) {}
};

// 思路：遍历list2（为主），对比list1，如果list当前元素小于list2的节点，则插入到list2节点的前方，直到条件结束
// 注意处理head节点

//

// class Solution {
// public:
//     ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
//         ListNode *head = list2;
//
//         ListNode *p1 = list1;
//         ListNode *p2_prev = nullptr;
//         ListNode *p2_curr = list2;
//
//         while (p2_curr != nullptr && p1 != nullptr) {
//             while (p1->val < p2_curr->val) {
//                 // insert
//             }
//         }
//     }
// };

// 当前思路的问题：
//
// 试图在list2中插入list1的节点会使逻辑变得复杂
// 需要处理很多边界情况，如头节点的变更
// 插入操作需要额外的指针操作，容易出错

// 推荐的最优思路：
// 使用双指针 + 哨兵节点的方法：
// 创建一个哨兵节点（dummy node）简化边界处理
// 使用两个指针分别遍历两个链表
// 比较当前节点值，将较小的节点连接到结果链表
// 处理剩余节点


class Solution {
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        if (list1 == nullptr) return list2; // 注意这里！！！！
        if (list2 == nullptr) return list1; // 注意这里！！！！

        ListNode dummy(0);          // Dummy node, value doesn't matter
        ListNode *current = &dummy; // Current pointer for building result list

        ListNode *p1 = list1;       // Pointer to current node in list1
        ListNode *p2 = list2;       // Pointer to current node in list2

        // 当两个链表都不为空时进行合并 / Merge while both lists are not empty
        while (p1 != nullptr && p2 != nullptr) {
            if (p1->val < p2->val) {
                current->next=p1;
                p1 = p1->next;
            }else {
                current->next=p2;
                p2=p2->next;
            }
            current = current->next;
        }

        // Connect remaining non-empty list to the end
        current->next = p1 == nullptr ? p2 : p1;
        return dummy.next;
    }
};
