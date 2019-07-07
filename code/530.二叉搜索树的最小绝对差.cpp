/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
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
    int getMinimumDifference(TreeNode* root) {
        res = INT_MAX;
        prev = nullptr;
        inorder(root);
        return res;
    }

private:
    void inorder(TreeNode* root)
    {
        if(!root)
            return;
        inorder(root->left);
        if(prev)
            res = min(res, root->val - *prev);
        prev = &root->val;
        inorder(root->right);
    }
    int* prev;
    int res;
};

