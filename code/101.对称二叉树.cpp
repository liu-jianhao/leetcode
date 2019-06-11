/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr)
            return true;

        return judge(root->left, root->right);
    }

    bool judge(TreeNode *leftRoot, TreeNode *rightRoot)
    {
        if(leftRoot == nullptr && rightRoot == nullptr)
            return true;        
        if(leftRoot == nullptr || rightRoot == nullptr)
            return false;        
        if(leftRoot->val == rightRoot->val)
            return judge(leftRoot->left, rightRoot->right) 
                    && judge(leftRoot->right, rightRoot->left);
        return false;
    }
};

