/*
 * @lc app=leetcode.cn id=491 lang=cpp
 *
 * [491] 递增子序列
 */
class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> res;
        vector<int> sub;
        rec(nums, res, 0, sub);
        return vector<vector<int>>(res.begin(), res.end());
    }

    void rec(const vector<int>& nums, set<vector<int>>& res, int index, vector<int>& sub)
    {
        if(sub.size() > 1)
        {
            res.insert(sub);
        }

        for(int i = index; i < nums.size(); ++i)
        {
            if(sub.empty() || nums[i] >= sub.back())
            {
                sub.push_back(nums[i]);
                rec(nums, res, i+1, sub);
                sub.pop_back();
            }
            else
            {
                rec(nums, res, i+1, sub);
            }
        }
    }
};

