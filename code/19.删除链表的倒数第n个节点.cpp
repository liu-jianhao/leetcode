/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第N个节点
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr || head->next == nullptr)
            return nullptr;
        ListNode *fast = head;

        while(fast && n--)
        {
            fast = fast->next;
        }

        if(fast == nullptr)
            return head->next;

        ListNode *pre = head;
        while(fast->next)
        {
            pre = pre->next;
            fast = fast->next;
        }
        pre->next = pre->next->next;
        return head;
    }
};

