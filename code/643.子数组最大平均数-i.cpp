/*
 * @lc app=leetcode.cn id=643 lang=cpp
 *
 * [643] 子数组最大平均数 I
 */
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int curSum = 0;
        int res;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(i < k)
            {
                curSum += nums[i];
                if(i == k-1)
                    res = curSum;
            }
            else
            {
                curSum = curSum - nums[i-k] + nums[i];
                res = max(res, curSum);
            }
        }
        return (double)res/k;
    }
};

