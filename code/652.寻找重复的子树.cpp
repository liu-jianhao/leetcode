/*
 * @lc app=leetcode.cn id=652 lang=cpp
 *
 * [652] 寻找重复的子树
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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> counts;
        vector<TreeNode*> res;
        serialize(root, counts, res);
        return res;
    }

    string serialize(TreeNode* root, unordered_map<string, int>& counts, vector<TreeNode*>& res)
    {
        if(!root)
            return "#";
        string key = to_string(root->val) + "," 
                    + serialize(root->left, counts, res) + ","
                    + serialize(root->right, counts, res);
        if(++counts[key] == 2)
            res.push_back(root);
        return key;
    }
};

