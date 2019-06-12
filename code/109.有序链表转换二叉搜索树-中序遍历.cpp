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
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        int len = getLength(head);
        p = head;
        return construct(0, len - 1);
    }
private:
    ListNode* p;
    int getLength(ListNode* head){
        int len = 0;
        while (head != nullptr)
        {
            ++len;
            head = head->next;
        }
        return len;
    }
    TreeNode* construct(int left, int right){
        if(left > right)
            return nullptr;
        else if (left == right)
        {
            TreeNode* root = new TreeNode(p->val);
            // 每当构建好一个树节点，链表就要后移一位
            p = p->next;
            return root;
        }
        int mid = left + (right - left) / 2;
        TreeNode* root = new TreeNode(-1);
        // 中序遍历
        root->left = construct(left, mid - 1);
        root->val = p->val;
        p = p->next;
        root->right = construct(mid + 1, right);
        return root;
    }
};