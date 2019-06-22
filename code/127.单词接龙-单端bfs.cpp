/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 */
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if(!dict.count(endWord))
            return 0;

        // BFS使用队列
        queue<string> q;
        q.push(beginWord);
        int step = 0;

        while(!q.empty())
        {
            ++step;
            for(int size = q.size(); size > 0; --size)
            {
                string w = q.front();
                q.pop();
                // 遍历 word 的每个字符
                for(int i = 0; i < w.size(); ++i)
                {
                    char ch = w[i];
                    // 替换
                    for(int j = 'a'; j <= 'z'; ++j)
                    {
                        w[i] = j;
                        // 相同说明找到了
                        if(w == endWord)
                            return step + 1;

                        // 字典中没有就跳过
                        if(!dict.count(w))
                            continue;

                        // 删掉字典中的已经遍历过了的
                        dict.erase(w);

                        q.push(w);
                    }
                    // 恢复原样
                    w[i] = ch;
                }
            }
        }

        return 0;
    }
};

