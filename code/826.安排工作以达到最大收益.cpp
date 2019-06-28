/*
 * @lc app=leetcode.cn id=826 lang=cpp
 *
 * [826] 安排工作以达到最大收益
 */
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        const int n = difficulty.size();
        vector<pair<int, int>> jobs;

        for(int i = 0; i < n; ++i)
        {
            jobs.push_back(make_pair(difficulty[i], profit[i]));
        }

        sort(jobs.begin(), jobs.end());
        sort(worker.begin(), worker.end());

        int res = 0;
        int i = 0;
        int best = 0;
        for(int level : worker)
        {
            while(i < n && level >= jobs[i].first)
            {
                best = max(best, jobs[i++].second);
            }
            res += best;
        }
        return res;
    }
};

