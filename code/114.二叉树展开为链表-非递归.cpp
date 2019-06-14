/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
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
    void flatten(TreeNode* root) {
        if(root == nullptr)
            return;
        
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty())
        {
            TreeNode *cur = s.top();
            s.pop();
            if(cur->right != nullptr)
                s.push(cur->right);
            if(cur->left != nullptr)
                s.push(cur->left);
            if(!s.empty())
                cur->right = s.top();

            cur->left = nullptr;
        } 
    }
};

