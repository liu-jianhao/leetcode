/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.empty())
            return res;
        
        sort(nums.begin(), nums.end());
        rec(res, nums, 0, nums.size()-1);

        return res;
    }

    void rec(vector<vector<int>>& res, vector<int> nums, int left, int right)
    {
        if(left == right)
        {
            res.push_back(nums);
            return;
        }

        for(int i = left; i <= right; ++i)
        {
            if(i != left && nums[left] == nums[i])
                continue;
            swap(nums[left], nums[i]);
            rec(res, nums, left+1, right);
        }
    }
};
