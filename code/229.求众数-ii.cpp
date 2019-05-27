/*
 * @lc app=leetcode.cn id=229 lang=cpp
 *
 * [229] 求众数 II
 */
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        // ????????
        int x = 0, y = 0;
        int count1 = 0, count2 = 0;
        for (int n : nums)
        {
            if ((count1 == 0 || n == x) && n != y)
            {
                ++count1;
                x = n;
            }
            else if (count2 == 0 || n == y)
            {
                ++count2;
                y = n;
            }
            else
            {
                --count1;
                --count2;
            }
        }

        count1 = count2 = 0;
        for (int n : nums)
        {
            if (x == n)
            {
                ++count1;
            }
            else if (y == n)
            {
                ++count2;
            }
        }

        if(count1 > nums.size()/3)
            res.push_back(x);
        if(count2 > nums.size()/3 && x != y)
            res.push_back(y);
        
        return res;
    }
};
