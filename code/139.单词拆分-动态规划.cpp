/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> hash(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<bool> dp(n+1, false);

        dp[0] = true;

        for(int i = 1; i <= n; ++i)
        {
            for(int j = 0; j < i; ++j)
            {
                if(dp[j])
                {
                    const string sub = s.substr(j, i-j);
                    if(hash.count(sub))
                    {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[n];
    }
};

