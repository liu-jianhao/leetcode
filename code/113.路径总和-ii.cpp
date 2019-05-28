/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] ???? II
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        if(root == nullptr)
            return res;
        vector<int> sub;
        findpath(res, sub, root, sum, 0);
        return res;
    }

    void findpath(vector<vector<int>>& res, vector<int>& sub, TreeNode* root, int sum, int curSum)
    {
        if(root == nullptr)
            return;

        curSum += root->val;
        sub.push_back(root->val);
        if(curSum == sum && root->left == nullptr && root->right == nullptr)
        {
            res.push_back(sub);
            sub.pop_back();
            return;
        }

        findpath(res, sub, root->left, sum, curSum);
        findpath(res, sub, root->right, sum, curSum);
        sub.pop_back();
    }
};

