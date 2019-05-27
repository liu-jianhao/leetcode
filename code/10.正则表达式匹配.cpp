/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */
class Solution {
public:
    bool isMatch(string s, string p) {
        return isMatch(s.c_str(), p.c_str());
    }

    bool isMatch(const char *s, const char *p)
    {
        if (*p == 0)
            return *s == 0;

        auto first_match = *s && (*s == *p || *p == '.');

        if (*(p + 1) == '*')
            return isMatch(s, p + 2) || (first_match && isMatch(++s, p));
        else
            return first_match && isMatch(++s, ++p);
    }
};
