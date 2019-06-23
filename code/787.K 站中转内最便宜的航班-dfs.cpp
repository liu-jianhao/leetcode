/*
 * @lc app=leetcode.cn id=787 lang=cpp
 *
 * [787] K 站中转内最便宜的航班 
 */
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        unordered_map<int, vector<pair<int, int>>> graph;
        for(auto f : flights)
        {
            graph[f[0]].emplace_back(f[1], f[2]);
        }
        vector<int> visited(n, 0);
        visited[src] = 1;
        int res = INT_MAX;
        dfs(src, dst, K+1, 0, visited, graph, res);
        return res == INT_MAX ? -1 : res;
    }

    void dfs(int src, int dst, int k, int cost, vector<int>& visited, 
        unordered_map<int, vector<pair<int, int>>>& g, int& res)
    {
        if(src == dst)
        {
            res = cost;
            return;
        }

        if(k == 0)
            return;

        for(auto p : g[src])
        {
            if(visited[p.first])
                continue;
            if(cost + p.second > res)
                continue;
            visited[p.first] = 1;
            dfs(p.first, dst, k-1, cost + p.second, visited, g, res);
            visited[p.first] = 0;
        }
    }
};

