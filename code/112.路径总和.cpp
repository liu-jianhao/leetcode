/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
    bool hasPathSum(TreeNode* root, int sum) {
        return dfs(root, sum, 0);
    }
    
    bool dfs(TreeNode* root, int sum, int cur) {
       	if(root == nullptr)
            return false;
        
        cur += root->val;
        if(cur == sum && root->left == nullptr && root->right == nullptr) {
            return true;
        }
        
        bool left = dfs(root->left, sum, cur);
        bool right = dfs(root->right, sum, cur);
        
        return left || right;
    }
};

