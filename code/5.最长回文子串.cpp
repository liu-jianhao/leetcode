/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */
class Solution {
public:
    string longestPalindrome(string s) {
		if(s.empty())
			return "";
		int maxi = s.size();
        // [i][j]表示以i为起始j为结尾的子字符串是否为回文
		vector<vector<bool>> dp(maxi, vector<bool>(maxi));
        int start = 0, longest = 1;
		// 初始化dp
		for(int i = 0; i < maxi-1; ++i)
		{
			dp[i][i] = true;
			if(s[i] == s[i+1])
            {
                dp[i][i+1] = true;
                start = i;
				longest = 2;
            }
		}
		
        // 从长度为3开始
		for(int len = 3; len <= maxi; ++len)
		{
			for(int i = 0; i+len-1 < maxi; ++i)
			{
                // j表示子字符串的结尾
				int j = i + len - 1;
				if(s[i] == s[j] && dp[i+1][j-1] == true)
				{
					dp[i][j] = true;
					start = i;
					longest = len;
				}
			}
		}

		return s.substr(start, longest);
    }
};