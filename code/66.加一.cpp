/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size();
        for(int i = size-1; i >= 0; --i)
        {
            digits[i]++;
            digits[i] %= 10;
            if(digits[i] != 0)
                return digits;
        }
        digits.resize(size+1);
        digits[0] = 1;
        return digits;
    }
};

