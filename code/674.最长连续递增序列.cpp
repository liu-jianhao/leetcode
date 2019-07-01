/*
 * @lc app=leetcode.cn id=674 lang=cpp
 *
 * [674] 最长连续递增序列
 */
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.empty())
            return 0;
        
        int maxLen = 1;
        int curLen = 1;
        for(int i = 1; i < nums.size(); ++i)
        {
            if(nums[i] > nums[i-1])
            {
                curLen++;
            }
            else
            {
                maxLen = max(maxLen, curLen);
                curLen = 1;
            }
        }
        maxLen = max(maxLen, curLen);
        return maxLen;
    }
};

