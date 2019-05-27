/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 求众数
 */
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj = nums[0];
        int count = 1;
        for(int i = 1; i < nums.size(); ++i)
        {
            if(nums[i] == maj)
                count++;
            else
            {
                if(--count == 0)
                {
                    maj = nums[i];
                    count = 1;
                }
            }
        }
        return maj;
    }
};

