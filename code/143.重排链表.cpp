/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
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
    void reorderList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return;
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        // 先将链表分为两半
        while(fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // 将后半部分反转
        ListNode* needReverser = slow->next;
        slow->next = nullptr;
        needReverser = reverse(needReverser);
        
        // 最后后半部分一个一个插入到前半部分
        ListNode* cur = head;
        while(cur && needReverser)
        {
            ListNode* curSecond = needReverser;
            needReverser = needReverser->next;
            ListNode* nextCur = cur->next;
            curSecond->next = cur->next;
            cur->next = curSecond;
            
            cur = nextCur;
        }
    }
    
    ListNode* reverse(ListNode* head)
    {
        ListNode* p1 = nullptr;
        ListNode* p2 = head;
        ListNode* p3 = p2;
        
        while(p2)
        {
            p3 = p2->next;
            p2->next = p1;
            p1 = p2;
            p2 = p3;
        }
        return p1;
    }
};

