/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
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
    bool hasCycle(ListNode *head) {
        if(head == nullptr)
            return false;

        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next)
        {
            if(slow == fast)
                return true;
            slow = slow->next;
            fast = fast->next->next;
        }

        return false;
    }
};

