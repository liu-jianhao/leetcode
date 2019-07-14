/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.empty() || postorder.empty() || inorder.size() != postorder.size())
            return nullptr;
        
        return buildTree(postorder, postorder.size()-1, inorder, 0, inorder.size());
    }

    TreeNode* buildTree(vector<int>& postorder, int k, vector<int>& inorder, int start, int end)
    {
        TreeNode* root = nullptr;
        if(k >= 0)
        {
            for(int j = start; j < end; ++j)
            {
                if(postorder[k] == inorder[j])
                {
                    root = new TreeNode(postorder[k]);
                    root->left = buildTree(postorder, k-(end-j), inorder, start, j);
                    root->right = buildTree(postorder, k-1, inorder, j+1, end);
                    return root;
                }
            }
        }
        return root;
    }
};

