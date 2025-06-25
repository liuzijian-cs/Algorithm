//
// Created by alpha on 2025/6/25.
//

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    // 构造函数 / Constructor
    ListNode(int x) : val(x), next(nullptr) {}
};

// |>>>>>>>>a>>>>>>>>>|>>>>>>>>>b>>>>>>>>|>>>>>>c>>>>>|
//                    |                 slow          |
//                    |<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<|
// fast: a + nb + nc + b
// slow = a + b
// fast = 2 * slow
// a + nb + nc + b = 2a + 2b
// a  = (n-1)b + nc = (n-1)(b+c) + c
// slow再走c的距离刚好到交点，这个距离也是从开始到交点的距离



// 38.51% - 46.77%
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head, *slow = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                ListNode *connect = head;
                while (connect != slow) {
                    slow = slow->next;
                    connect = connect->next;
                }
                return connect;
            }
        }
        return nullptr;
    }
};

