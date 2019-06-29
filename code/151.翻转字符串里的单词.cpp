/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 翻转字符串里的单词
 */
class Solution {
public:
    string reverseWords(string s) {
        string res;

        for(int i = s.size() - 1; i >= 0;)
        {
            while(i >= 0 && s[i] == ' ')
                --i;
            if(i < 0)
                break;
            int j = i - 1;
            while(j >= 0 && s[j] != ' ')
                --j;
            res += s.substr(j+1, i-j);
            res += ' ';
            i = j - 1;
        }
        res.pop_back();
        return res;
    }
};

