/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr)
            return head;

        ListNode* cur = head;
        ListNode* pre = nullptr;

        while(cur && cur->next)
        {
            ListNode* next = cur->next;
            ListNode* nnext = next->next;

            if(pre)
                pre->next = next;
            else
                head = next;
            
            next->next = cur;
            cur->next = nnext;

            pre = cur;
            cur = nnext;
        }

        return head;
    }
};

