/*
 * @lc app=leetcode.cn id=547 lang=cpp
 *
 * [547] 朋友圈
 */
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int res = 0;
        for(int i = 0; i < M.size(); ++i)
        {
            if(M[i][i] == 1)
            {
                res++;
                dfs(M, i);
            }
        }
        return res;
    }

    void dfs(vector<vector<int>> &M, int k)
    {
        M[k][k] = 0;
        for (int i = 0; i < M.size(); ++i)
        {
            if (M[k][i] == 1 && M[i][i] == 1)
            {
                dfs(M, i);
            }
        }
    }
};
