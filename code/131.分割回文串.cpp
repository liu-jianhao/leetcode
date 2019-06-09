/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */
// 类似于全排列
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> sub;
        dfs(res, sub, s, 0);
        return res;
    }
    
    void dfs(vector<vector<string>>& res, vector<string>& sub, string& s, int index)
    {
        if(index >= s.size())
        {
            res.push_back(sub);
            return;
        }
        
        for(int i = index; i < s.size(); ++i)
        {
            string str = s.substr(index, i - index + 1);
            if(isHui(str))
            {
                sub.push_back(str);
                dfs(res, sub, s, i+1);
                sub.pop_back();
            }
        }
    }
    
    bool isHui(string s)
    {
        int start = 0;
        int end = s.size()-1;
        while(start < end)
        {
            if(s[start++] != s[end--])
                return false;
        }
        return true;
    } 
};

