/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> sub;
        res.push_back(sub);
        rec(nums, res, sub, 0);
        return res;
    }

    void rec(vector<int>& nums, vector<vector<int>>& res, vector<int>& sub, int index)
    {
        for(int i = index; i < nums.size(); ++i)
        {
            sub.push_back(nums[i]);
            res.push_back(sub);
            rec(nums, res, sub, i+1);
            sub.pop_back();
        }
    }
};

