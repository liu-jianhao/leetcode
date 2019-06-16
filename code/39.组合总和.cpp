/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        if(candidates.empty())
            return res;

        vector<int> subRes;       
        rec(res, subRes, candidates, target, 0);

        return res;
    }

    void rec(vector<vector<int>>& res, vector<int>& subRes, vector<int>& candidates, int target, int index)
    {
        // 递归终止条件
        if(target < 0)
            return;
        // 找到一个子结果
        if(0 == target)
        {
            res.push_back(subRes);
            return;
        }

        for(int i = index; i < candidates.size(); ++i)
        {
            // 做某些处理
            subRes.push_back(candidates[i]);
            rec(res, subRes, candidates, target-candidates[i], i);
            // 回滚处理
            subRes.pop_back();
        }
    }
};

