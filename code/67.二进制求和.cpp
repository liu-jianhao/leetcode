/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */
class Solution
{
public:
    string addBinary(string a, string b)
    {
        if (b.size() > a.size())
        {
            string temp = b;
            b = a;
            a = temp;
        }
        int i = a.size() - 1;
        int j = b.size() - 1;
        if (i != j)
        {
            for (int k = 0; k < i - j; k++)
                b = "0" + b;
        }
        int count = 0; //进位数
        for (int k = i; k >= 0; k--)
        {
            if (a[k] - '0' + b[k] - '0' + count == 0)
            {
                a[k] = '0';
                count = 0;
            }
            else if (a[k] - '0' + b[k] - '0' + count == 1)
            {
                a[k] = '1';
                count = 0;
            }
            else if (a[k] - '0' + b[k] - '0' + count == 3)
            {
                a[k] = '1';
                count = 1;
            }
            else
            {
                a[k] = '0';
                count = 1;
            }
        }
        if (count == 1)
            a = '1' + a;
        return a;
    }
};