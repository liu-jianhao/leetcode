/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */
class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.empty())
            return 0;
        int pos = s.size()-1;
        // 去掉最后的空格
        while(pos >= 0 && s[pos] == ' ')
        {
            s.erase(pos);
            --pos;
        }
        // 找到最后的空格
        while(pos >= 0 && s[pos] != ' ')
        {
            --pos;
        }

        return s.size() - pos - 1;
    }
};

