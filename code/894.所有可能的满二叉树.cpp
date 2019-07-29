/*
 * @lc app=leetcode.cn id=894 lang=cpp
 *
 * [894] 所有可能的满二叉树
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
    vector<TreeNode*> allPossibleFBT(int N) {
        if(N % 2 == 0)
            return {};
        if(N == 1)
            return { new TreeNode(0) };
        vector<TreeNode*> ans;
        for(int i = 1; i < N; i += 2)
        {
            for(auto l : allPossibleFBT(i))
            {
                for(auto r : allPossibleFBT(N - i - 1))
                {
                    auto root = new TreeNode(0);
                    root->left = l;
                    root->right = r;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
};

