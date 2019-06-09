/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] 求根到叶子节点数字之和
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
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
    
    long long dfs(TreeNode* root, long long sum)
    {
        if(root == nullptr)
            return 0;
        if(root->left == nullptr && root->right == nullptr)
        {
            return sum += root->val;
        }
        sum += root->val;
        return dfs(root->left, 10*sum) + dfs(root->right, 10*sum);
    }
};

