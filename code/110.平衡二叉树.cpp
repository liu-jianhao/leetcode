/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
    bool isBalanced(TreeNode* root) {
        helper(root);
        return res;
    }

    int helper(TreeNode* root)
    {
        if(root == nullptr)
            return 0;
        int left = helper(root->left) + 1;
        int right = helper(root->right) + 1;
        if(abs(left-right) > 1)
            res = false;
        return max(left, right);
    }
private:
    bool res = true;
};

