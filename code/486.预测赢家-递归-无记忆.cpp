/*
 * @lc app=leetcode.cn id=486 lang=cpp
 *
 * [486] 预测赢家
 */
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        return getScore(nums, 0, nums.size()-1) >= 0;
    }

    int getScore(vector<int>& nums, int l, int r)
    {
        if(l == r)
            return nums[l];
        return max(nums[l] - getScore(nums, l+1, r), nums[r] - getScore(nums, l, r-1));
    }
};

