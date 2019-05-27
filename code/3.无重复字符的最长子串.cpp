/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty())
        {
            return 0;
        }
        
        vector<int> map(128, -1);
        
        int current = 0;
        int longest = 0;
        
        for(unsigned i = 0; i < s.size(); ++i)
        {
            if(map[s[i]] == -1 || i - current > map[s[i]])
            {
                current++;
                longest = max(longest, current);
            }
            else
                current = i - map[s[i]];
            map[s[i]] = i;
        }
        
        return longest; 
    }
};

