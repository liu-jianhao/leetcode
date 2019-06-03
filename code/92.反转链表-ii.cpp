/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 要求一趟扫描
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *dummy = new ListNode(0);
        ListNode *pre = dummy, *cur;
        dummy->next = head;
        for(int i = 0; i < m-1; ++i)
        {
            pre = pre->next;
        }
        cur = pre->next;
        for(int i = 0; i < n-m; ++i)
        {
            ListNode *temp = pre->next;
            pre->next = cur->next;
            cur->next = cur->next->next;
            pre->next->next = temp;
        }

        return dummy->next;
    }
};

