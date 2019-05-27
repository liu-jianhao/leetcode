/*
 * @lc app=leetcode.cn id=260 lang=cpp
 *
 * [260] 只出现一次的数字 III
 */
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> res(2);
        
        // 得到只出现一次的两个数的异或结果
        int sum = nums[0];
        for(int i = 1; i < nums.size(); ++i)
        {
            sum ^= nums[i];
        }

        // 取出该数最低位的1
        int flag = sum & (~(sum-1));

        for(int n : nums)
        {
            if(n & flag)
                res[0] ^= n;
            else
                res[1] ^= n;
        }
        return res;
    }
};

