/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        for(int i = 0; i < board.size(); ++i)
        {
            for(int j = 0; j < board[0].size(); ++j)
            {
                if(dfs(board, word, 0, i, j, visited))
                    return true;
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, string& word, int widx, int i, int j, vector<vector<bool>>& visited)
    {
        if(widx == word.size())
            return true;
        
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[widx] || visited[i][j] == true)
            return false;

        visited[i][j] = true;
        bool res = dfs(board, word, widx + 1, i + 1, j, visited) ||
                   dfs(board, word, widx + 1, i, j + 1, visited) ||
                   dfs(board, word, widx + 1, i - 1, j, visited) ||
                   dfs(board, word, widx + 1, i, j - 1, visited);
        visited[i][j] = false;
        return res;
    }
};

