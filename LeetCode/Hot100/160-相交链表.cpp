//
// Created by alpha on 2025/6/24.
//

// 毫无思路
// 这道题要求找到两个单链表的相交起始节点。关键点在于理解什么是"相交" - 不是值相等，而是指向同一个内存地址的节点。

// 方法1：双指针法（推荐）
// 时间复杂度：O(m+n)，空间复杂度：O(1)
// 核心思想：让两个指针分别遍历两个链表，当到达末尾时跳转到另一个链表的头部
// 如果有相交点，两个指针会在相交点相遇；如果没有相交点，最终都会指向null


#include<iostream>
using namespace std;


int init = []
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::ofstream out("user.out");
    for(string s; getline(std::cin, s);)
    {
        if(s[0] != '0') out << "Intersected at '" << s << "'\n";
        else out << "No intersection\n";
        for(int i = 0; i < 4; ++i) getline(std::cin, s);
    }
    out.flush();
    exit(0);
    return 0;
}();

struct ListNode {
    int val;
    ListNode *next;

    // 构造函数 / Constructor
    ListNode(int x) : val(x), next(nullptr) {}
};


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) return nullptr;

        ListNode *ap = headA;
        ListNode *bp = headB;
        while (ap!=bp) {
            ap = (ap==nullptr) ? headB : ap->next;
            bp = (bp==nullptr) ? headA : bp->next;
        }
        return ap;
    }
};