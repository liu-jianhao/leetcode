/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head)
        {
            return head;
        }

        ListNode* slow = head;
        ListNode* fast = head->next;
        bool flag = true;

        while(flag && fast && fast->next && fast->next->next)
        {
            if(slow == fast)
            {
                flag = false;
            }
            if(fast == nullptr)
            {
                flag = true;
                break;
            }
            slow = slow->next;
            fast = fast->next->next;
        }

        if(flag)
        {
            return nullptr;
        }

        fast = head;
        while(fast != slow)
        {
            fast = fast->next;
            slow = slow->next;
        }

        return slow;
    }
};

