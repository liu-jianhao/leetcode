/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        if(n <= 0 || k <= 0 || k > n)
            return res;
        vector<int> subRes;
        rec(res, subRes, n, k, 1);
        return res;
    }

    void rec(vector<vector<int>>& res, vector<int>& subRes, int n, int k, int index)
    {
        if(subRes.size() == k)
        {
            res.push_back(subRes);
            return;
        }

        for(int i = index; i <= n; ++i)
        {
            subRes.push_back(i);
            rec(res, subRes, n, k, i+1);
            subRes.pop_back();
        }
    }
};

