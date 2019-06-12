/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size());
    }

    TreeNode* helper(vector<int>& nums, int first, int last)
    {
        if(first >= last)
            return nullptr;

        int mid = (first + last) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = helper(nums, first, mid);
        root->right = helper(nums, mid+1, last);
        return root;
    }
};

