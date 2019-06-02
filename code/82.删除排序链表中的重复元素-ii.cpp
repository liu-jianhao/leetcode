/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* p = new ListNode(0);
        p->next = head;
        head = p;

        ListNode* pre, *cur;
        while(p->next)
        {
            pre = p->next;
            cur = pre;
            while(cur->next && cur->val == cur->next->val)
                cur = cur->next;
            if(pre != cur)
                p->next = cur->next;
            else
                p = p->next;
        }

        return head->next;
    }
};

