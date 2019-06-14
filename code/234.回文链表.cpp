/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *fast = head, *rev = nullptr;
        while(fast && fast->next)
        {
            fast = fast->next->next;
            ListNode *tmp = slow->next;
            // ?????????
            slow->next = rev;
            rev = slow;
            slow = tmp;
        }

        if(fast)
            slow = slow->next;

        // ???????????????????
        while(slow && rev)
        {
            if(slow->val != rev->val)
                return false;
            slow = slow->next;
            rev = rev->next;
        }

        return true;
    }
};

