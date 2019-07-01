/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        if(intervals.empty())
            return res;
        
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b){
            return a[0] < b[0];
        });

        res.push_back(intervals[0]);

        for(int i = 1; i < intervals.size(); ++i)
        {
            if(res.back()[1] < intervals[i][0])
                res.push_back(intervals[i]);
            else
                res.back()[1] = max(res.back()[1], intervals[i][1]);
        }
        return res;
    }
};

