/*
 * @lc app=leetcode.cn id=109 lang=cpp
 *
 * [109] 有序链表转换二叉搜索树
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 模仿数组的方式，但每次找中间节点都要遍历一半的链表，效率不高
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return helper(head, nullptr);
    }

    TreeNode* helper(ListNode* head, ListNode* tail)
    {
        if(head == tail)
            return nullptr;

        ListNode* mid = getMid(head, tail);
        TreeNode* root = new TreeNode(mid->val);
        root->left = helper(head, mid);
        root->right = helper(mid->next, tail);
        return root;
    }

    ListNode* getMid(ListNode* head, ListNode* tail)
    {
        if(head == nullptr || head->next == nullptr)
            return head;

        ListNode *slow, *fast;
        slow = fast = head;
        while(fast != tail && fast->next != tail)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

