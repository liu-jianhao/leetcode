/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr)
            return l2;
        if(l2 == nullptr)
            return l1;
        
        ListNode* dummy = new ListNode(0);

        ListNode* p1 = l1;
        ListNode* p2 = l2;
        ListNode* p3 = dummy;

        int carry = 0;

        while(p1 || p2)
        {
            int sum = carry;
            if(p1)
            {
                sum += p1->val;
                p1 = p1->next;
            }
            if (p2)
            {

                sum += p2->val;
                p2 = p2->next;
            }

            carry = sum / 10;
            p3->next = new ListNode(sum % 10);
            p3 = p3->next;
        }
        if (carry)
            p3->next = new ListNode(1);
        return dummy->next;
    }
};