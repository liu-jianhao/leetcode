/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(0);
        dummy.next = head;
        head = &dummy;
        ListNode* pre = head;
        ListNode* cur = pre->next;
        while(cur)
        {
            if(cur->val == val)
                pre->next = cur->next;
            else
                pre = cur;            
            cur = cur->next;
        }
        return head->next;
    }
};

