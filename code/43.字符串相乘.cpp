/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
 */
class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1.empty() || num2.empty())
            return "";
        if(num1 == "0" || num2 == "0")
            return "0";

        int l1 = num1.size();
        int l2 = num2.size();
        int k = l1 + l2 - 2;

        int carrryBit = 0;
        vector<int> tmpres(l1 + l2);

        for(int i = 0; i < l1; ++i)
        {
            for(int j = 0; j < l2; ++j)
            {
                tmpres[k - i - j] += (num1[i] - '0') * (num2[j] - '0');
            }
        }

        int carryBit = 0;
        for(int i = 0; i < l1 + l2; ++i)
        {
            tmpres[i] += carrryBit;
            carrryBit = tmpres[i] / 10;
            tmpres[i] %= 10;
        }     

        int i = k + 1;
        while(tmpres[i] == 0)
        {
            --i;
        }
        if(i < 0)
        {
            return "0";
        }

        string res;
        for(; i >= 0; --i)
        {
            res.push_back(tmpres[i] + '0');
        }
        return res;
    }
};

