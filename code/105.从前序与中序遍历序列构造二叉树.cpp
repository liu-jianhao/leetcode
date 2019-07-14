/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty() || inorder.empty() || preorder.size() != inorder.size())        
            return nullptr;
        
        return buildTree(preorder, 0, inorder, 0, inorder.size());
    }

    TreeNode* buildTree(vector<int>& preorder, int k, vector<int>& inorder, int start, int end)
    {
        TreeNode* root = nullptr;
        if(k < preorder.size())
        {
            for(int j = start; j < end; ++j)
            {
                if(preorder[k] == inorder[j])
                {
                    root = new TreeNode(preorder[k]);
                    root->left = buildTree(preorder, k+1, inorder, start, j);
                    root->right = buildTree(preorder, k+j-start+1, inorder, j+1, end);
                    return root;
                }
            }
        }
        return root;
    }
};

