/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> hash(wordDict.begin(), wordDict.end());
        unordered_map<string, bool> memo;
        return wordBreak(s, hash, memo);
    }

    bool wordBreak(const string& s, unordered_set<string>& hash, unordered_map<string, bool>& memo)
    {
        auto it = memo.find(s);
        if(it != memo.end())
            return it->second;

        if(hash.count(s))
            return memo[s] = true;
        
        for(int pos = 1; pos < s.size(); ++pos)
        {
            const string right = s.substr(pos);
            if(!hash.count(right))
                continue;

            const string left = s.substr(0, pos);
            if(wordBreak(left, hash, memo))
                return memo[s] = true;
        }
        return memo[s] = false;
    }
};

