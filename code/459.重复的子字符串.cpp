/*
 * @lc app=leetcode.cn id=459 lang=cpp
 *
 * [459] 重复的子字符串
 */
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int len = s.size();
        for(int t = 1; t <= len/2; ++t)
        {
            if(len % t)
                continue;
            int i;
            for(i = t; i < len && s[i] == s[i%t]; ++i) ;
            if(i == len)
                return true;
        }
        return false;
    }
};

