/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */
class Solution {
public:
    int longestValidParentheses(string s) {
        int left = 0, right = 0, maxLength = 0;
        for(int i = 0; i < s.size(); ++i)
        {
            if(s[i] == '(')
                ++left;
            else
                ++right;
            if(left == right)
                maxLength = max(maxLength, 2 * left);
            else if(right > left)
                left = right = 0;
        }

        left = right = 0;
        for(int i = s.size()-1; i >= 0; --i)
        {
            if(s[i] == '(')
                ++left;
            else
                ++right;
            if(left == right)
                maxLength = max(maxLength, 2 * left);
            else if(left > right)
                left = right = 0;
        }

        return maxLength;
    }
};

