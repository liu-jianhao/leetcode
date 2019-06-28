/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */
class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> map(128, 0);
        for(int i = 0; i <  S.size(); ++i)
        {
            map[S[i]] = i;
        }

        vector<int> res;
        int start, end;
        start = end = 0;
        for(int i = 0; i < S.size(); ++i)
        {
            end = max(end, map[S[i]]);
            if(i == end)
            {
                res.push_back(end - start + 1);
                start = end + 1;
            }
        }
        return res;
    }
};

