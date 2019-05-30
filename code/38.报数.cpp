/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 报数
 */
class Solution {
public:
    string countAndSay(int n) {
        if(n == 1)
            return "1";
        string strlast = countAndSay(n-1);
        int count = 1;
        string res;
        for(int i = 0; i < strlast.size(); ++i)
        {
            if(strlast[i] == strlast[i+1])
            {
                count++;
                continue;
            }
            else
            {
                if(strlast[i] != strlast[i+1])
                {
                    res += to_string(count) + strlast[i];
                    count = 1;
                }
            }
        }
        return res;
    }
};

