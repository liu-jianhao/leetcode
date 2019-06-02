/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] ????
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* p = new ListNode(0);
        p->next = head;
        ListNode* pre = p;
        while(pre->next != nullptr && pre->next->val < x)
            pre = pre->next;
        ListNode* cur = pre;
        while(cur->next != nullptr)
        {
            if(cur->next->val < x)
            {
                ListNode* next = cur->next;
                cur->next = next->next;
                next->next = pre->next;
                pre->next = next;
                pre = pre->next;
            }
            else
            {
                cur = cur->next;
            }
        }
        
        return p->next;
    }
};

