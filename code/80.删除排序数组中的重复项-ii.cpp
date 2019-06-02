/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除排序数组中的重复项 II
 */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for(int i = 2; i < nums.size(); ++i)
        {
            if(nums[i] == nums[i-2-count])
                ++count;
            else
                nums[i - count] = nums[i];
        }
        return n - count;
    }
};

