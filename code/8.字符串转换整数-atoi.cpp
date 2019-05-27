/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */
class Solution {
public:
    int myAtoi(string str) {
        long res = 0;
        bool isUint = true;
        bool isStart = true;
        for(int i = 0; i < str.size(); ++i)
        {
            if(str[i] == ' ' && isStart)
            {
                continue;
            }
            else if(str[i] == '-' && isStart)
            {
                isStart = false;
                isUint = false;
            }
            else if(str[i] == '+' && isStart)
            {
                isStart = false;
                isUint = true;
            }
            else if(str[i] >= '0' && str[i] <= '9')
            {
                isStart = false;
                res = res * 10 + (str[i] - '0');
                if(res != (int)res)
                {
                    if(isUint) {
                        return INT_MAX;
                    }
                    else
                    {
                        return INT_MIN;
                    }
                }
            }
            else
            {
                break;
            }
        }
        if(!isUint)
            res = 0 - res;
        return res;
    }
};

