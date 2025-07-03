//
// Created by alpha on 2025/7/3.
//

// 思路：本质上是在反转链表的基础上进行分组处理
// 应该先需要派一个指针指向k+1节点确定不是null后处理档期组
// 对于反转链表的部分，每k个一组，采用头插法进行反转

// 你的思路基本正确：
//
// ✅ 确实需要基于反转链表的基础进行分组处理
// ✅ 需要先确定有足够的k个节点才进行反转
// ✅ 头插法是一个很好的反转方法

// 不过需要补充一些关键点：
//
// 需要记录每组的前驱节点，用于连接反转后的链表
// 需要处理边界条件：k=1、链表长度不足k等情况
// 需要正确处理每组反转后的连接关系


#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 100%-37.29%
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // 边界条件：空链表或 k<=1，直接返回
        // Boundary: if list empty or k<=1, no change needed
        if (!head || k <= 1) return head;

        // 创建虚拟头节点，简化头部操作
        // Create dummy head to simplify handling head changes
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev_group = &dummy;  // 指向每组反转前的「前驱节点」
                                        // Points to node before the current group

        while (true) {
            // 检查是否还有 k 个节点可反转
            // Check if there are at least k nodes left
            ListNode* check = prev_group;
            for (int i = 0; i < k && check; ++i) {
                check = check->next;
            }
            if (!check) break;  // 不足 k 个，退出 / fewer than k nodes

            // 标记本组的头、尾，以及下一组的起点
            // Record start, end of this group, and start of next group
            ListNode* group_start = prev_group->next;  // 本组反转前的第一个节点 / first node of this group
            ListNode* group_end   = check;             // 本组反转前的第 k 个节点 / kth node of this group
            ListNode* next_group  = group_end->next;   // 下一组的起点 / start of next group

            // 在 [group_start, group_end] 之间反转
            // Reverse nodes from group_start to group_end
            ListNode* prev = next_group;
            ListNode* curr = group_start;
            while (curr != next_group) {
                ListNode* nxt = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nxt;
            }

            // 连接反转后的子链表
            // Connect reversed group back to list
            prev_group->next = group_end;      // 接到本组新头 / connect previous part to new head
            group_start->next = next_group;    // 本组新尾接到下一组 / connect new tail to next group

            // 更新 prev_group 到本组新尾
            // Move prev_group to the new tail of this group
            prev_group = group_start;
        }

        return dummy.next;
    }
};