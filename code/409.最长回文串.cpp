/*
 * @lc app=leetcode.cn id=409 lang=cpp
 *
 * [409] 最长回文串
 */
class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> map(128);
        int even = 0, odd = 0, count = 0;
        int sum = 0;
        for(char c : s)
        {
            map[c]++;
        }

        for(int n : map)
        {
            if(n % 2 == 0)
                even += n;
            else
            {
                odd += n;
                ++count;
            }
        }

        if(odd == 0)
            sum = even;
        else
        {
            sum = even + odd - (count - 1);
        }

        return sum;
    }
};

