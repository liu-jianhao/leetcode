/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        if(k <= 0 || n < k)
            return res;
        vector<int> subRes; 
        dfs(k, n, res, subRes, 1);
        return res;
    }

    void dfs(int k, int target, vector<vector<int>>& res, vector<int>& subRes, int index)
    {
        if(target < 0 || k < 0)
            return;
        if (target == 0 && k == 0)
        {
            res.push_back(subRes);
            return;
        }

        for(int i = index; i < 10; ++i)
        {
            subRes.push_back(i);
            dfs(k-1, target-i, res, subRes, i+1);
            subRes.pop_back();
        }
    }
};

