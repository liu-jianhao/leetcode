/*
 * @lc app=leetcode.cn id=140 lang=cpp
 *
 * [140] 单词拆分 II
 */
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> hash(wordDict.begin(), wordDict.end());
        unordered_map<string, vector<string>> memo;
        return wordBreak(s, hash, memo);
    }
    vector<string> wordBreak(string& s, unordered_set<string>& hash, unordered_map<string, vector<string>>& memo)
    {
        auto p = memo.emplace(s, vector<string>());
        vector<string>& res = p.first->second;
        if(!p.second)
        {
            return res;
        }

        if(s.empty())
            return {};

        if(hash.count(s))
            res.push_back(s);

        for(int pos = 1; pos < s.size(); ++pos)
        {
            string right = s.substr(pos);
            if(!hash.count(right))
                continue;
            
            string left = s.substr(0, pos);
            vector<string> left_res = wordBreak(left, hash, memo);

            for(string lres : left_res)
                res.push_back(lres + " " + right);
        }

        return res;
    }
};

