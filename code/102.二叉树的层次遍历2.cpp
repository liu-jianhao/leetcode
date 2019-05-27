/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层次遍历
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        helper(res, root, 0);
        return res;
    }

    void helper(vector<vector<int>>& res, TreeNode* root, int level)
    {
        if(root == nullptr)
            return;

        if(res.size() < level+1)
            res.push_back(vector<int>());

        res[level].push_back(root->val);
        
        helper(res, root->left, level+1);
        helper(res, root->right, level+1);
    }
};
