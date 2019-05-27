/*
 * @lc app=leetcode.cn id=137 lang=cpp
 *
 * [137] 只出现一次的数字 II
 */
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int one = 0, two = 0, three;
        for(int n : nums)
        {
            // two的相应的位等于1，表示该位出现2次
            two |= (one & n);
            // one的相应的位等于1，表示该位出现1次
            one ^= n;
            // three的相应的位等于1，表示该位出现3次
            three = (one & two);

            // 如果相应的位出现3次，则该位重置为0
            two &= ~three;
            one &= ~three;
        }
        return one;
    }
};

