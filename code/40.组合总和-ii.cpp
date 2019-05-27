/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */
// 这道题最大的难点就是怎么去重
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        if(candidates.empty())
            return res;

        sort(candidates.begin(), candidates.end());
        vector<int> subRes;
        rec(res, subRes, candidates, target, 0);

        return res;
    }

    void rec(vector<vector<int>>& res, vector<int>& subRes, vector<int>& candidates, int target, int index)
    {
        if(target < 0)
            return;
        if(target == 0)
        {
            res.push_back(subRes);
            return;
        }

        for(int i = index; i < candidates.size(); ++i)
        {
            // 去重
            if(index != i && candidates[i] == candidates[i-1])
                continue;
            subRes.push_back(candidates[i]);
            rec(res, subRes, candidates, target-candidates[i], i+1);
            subRes.pop_back();
        }
    }
};
