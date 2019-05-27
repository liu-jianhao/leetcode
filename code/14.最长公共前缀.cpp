/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res;
        if(strs.empty())
            return res;

        string com = strs[0];
        for(int i = 0; i < com.size(); ++i)
        {
            char c = com[i];
            for(int j = 1; j < strs.size(); ++j)
            {
                if(strs[j][i] != c)
                    return res;
            }
            res += c;
        }

        return res;        
    }
};

