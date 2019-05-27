/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
    TreeNode *prev = nullptr;
public:
    bool helper(TreeNode* root){
        if(root == nullptr)
            return true;
        if(!helper(root->left))
            return false;
        if(prev && root->val <= prev->val)
            return false;
        prev = root;
        return helper(root->right);
    }

    bool isValidBST(TreeNode* root) {
        return helper(root);
    }
};
