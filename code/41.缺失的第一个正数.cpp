/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if(nums.empty())
            return 1;
        int len = nums.size();
        int i = 0;
        for(; i < len; ++i)
            while(nums[i] > 0 && nums[i] <= len && nums[i] != nums[nums[i]-1])
                    swap(nums[i], nums[nums[i]-1]);

        for(i = 0; i < len; ++i)
            if(nums[i] != i+1)
                break;

        return i+1;
    }
};

