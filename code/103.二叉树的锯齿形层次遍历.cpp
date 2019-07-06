/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层次遍历
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root)
        {
            return  res;
        }

        bool cur = false;
        queue<TreeNode*> que;
        que.push(root);

        while(!que.empty())
        {
            int count = que.size();
            vector<int> vec_tmp;
            while(count--)
            {
                TreeNode* tmp = que.front();
                que.pop();
                vec_tmp.push_back(tmp->val);
                if(tmp->left)
                {
                    que.push(tmp->left);
                }
                if(tmp->right)
                {
                    que.push(tmp->right);
                }
            }

            if(cur)
            {
                reverse(vec_tmp.begin(), vec_tmp.end());
            }

            cur = !cur;
            res.push_back(vec_tmp);
        }

        return res;
    }
};

