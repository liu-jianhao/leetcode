/*
 * @lc app=leetcode.cn id=752 lang=cpp
 *
 * [752] Open the Lock
 */
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        const string start = "0000";
        unordered_set<string> dead(deadends.begin(), deadends.end());
        if(dead.count(start))
            return -1;
        
        unordered_set<string> visited{start};
        queue<string> q;
        q.push(start);
        int step = 0;

        while(!q.empty())
        {
            ++step;
            int size = q.size();
            for(int i = 0; i < size; ++i)
            {
                string cur = q.front();
                q.pop();
                for(int j = 0; j < 4; ++j)
                {
                    for(int k = -1; k <= 1; k +=2)
                    {
                        string next = cur;
                        next[j] = (next[j] - '0' + k + 10) % 10 + '0';
                        if(next == target)
                            return step;

                        if(dead.count(next) || visited.count(next))
                            continue;

                        q.push(next);
                        visited.insert(next);
                    }
                }
            }
        }
        return -1;
    }
};

