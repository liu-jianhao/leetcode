/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层次遍历 II
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        dfs(res, root, 0);
        reverse(res.begin(), res.end());
        return res;        
    }

    void dfs(vector<vector<int>>& res, TreeNode* root, int level)
    {
        if(root == nullptr)
            return;
        
        if(res.size() < level+1)
            res.push_back(vector<int>());

        res[level].push_back(root->val);
        
        dfs(res, root->left, level+1);
        dfs(res, root->right, level+1);
    }
};

