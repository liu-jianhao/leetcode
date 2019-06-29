/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 */
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.empty())
            return true;
        if(s2.empty() || s1.size() > s2.size())
            return false;
        
        vector<int> s1_map(128, 0);
        vector<int> s2_map(128, 0);

        for(int i = 0; i < s1.size(); ++i)
        {
            ++s1_map[s1[i]];
        }

        for(int i = 0; i < s2.size(); ++i)
        {
            if(i >= s1.size())
            {
                --s2_map[s2[i-s1.size()]];
            }
            ++s2_map[s2[i]];
            if(s2_map == s1_map)
                return true;
        }
        return false;
    }
};

