/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == nullptr)
            return res;
        
        stack<TreeNode*> stack;
        stack.push(root);
        TreeNode* pre = nullptr;
        while(!stack.empty())
        {
            TreeNode* cur = stack.top();
            // 如果当前节点是叶子节点或上一个访问的节点为当前节点的子节点时，当前节点出栈
            if((cur->left == nullptr && cur->right == nullptr) || pre != nullptr && (pre == cur->left || pre == cur->right) )
            {
                res.push_back(cur->val);
                pre = cur;
                stack.pop();
            }
            else
            {
                if(cur->right)
                    stack.push(cur->right);
                if(cur->left)
                    stack.push(cur->left);
            }
        }
        return res;
    }
};

