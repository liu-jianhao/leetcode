/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
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
    int res = INT_MIN;
public:
    int maxPathSum(TreeNode* root) {
        getMax(root);
        return res;
    }

    int getMax(TreeNode* root)
    {
        if(root == nullptr)
            return 0;
        int left = max(0, getMax(root->left));
        int right = max(0, getMax(root->right));
        res = max(res, root->val + left + right);
        return max(left, right) + root->val;
    }
};

