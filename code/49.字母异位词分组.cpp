/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        if(strs.empty())
            return res;
        
        unordered_map<string, vector<string>> strMap;
        
        for(auto s : strs)
        {
            string tmp = s;
            sort(tmp.begin(), tmp.end());
            auto it = strMap.find(tmp);
            if(it == strMap.end())
            {
                strMap.insert(make_pair(tmp, vector<string>(1, string(s))));
            }
            else
            {
                it->second.push_back(s);
            }
        }

        for(auto vs : strMap)
        {
            res.push_back(vs.second);
        }

        return res;
    }
};

