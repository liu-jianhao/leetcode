/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
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
    int kthSmallest(TreeNode* root, int k) {
        return kth(root, k)->val;
    }

    TreeNode* kth(TreeNode* root, int& k)
    {
        TreeNode* res = nullptr;
        if(root->left)
            res = kth(root->left, k);

        if(res == nullptr && --k == 0)
            res = root;
        
        if(res == nullptr && root->right)
            res = kth(root->right, k);
        
        return res;
    }
};

