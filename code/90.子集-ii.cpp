/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */
// 怎么去重是关键
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> sub;
        sort(nums.begin(), nums.end());
        res.push_back(sub);

        rec(res, sub, nums, 0);

        return res;
    }

    void rec(vector<vector<int>>& res, vector<int>& sub, vector<int>& nums, int index)
    {
        for(int i = index; i < nums.size(); ++i)
        {
            if(i != index && nums[i] == nums[i-1])
                continue;
            sub.push_back(nums[i]);
            res.push_back(sub);
            rec(res, sub, nums, i+1);
            sub.pop_back();
        }
    }
};

