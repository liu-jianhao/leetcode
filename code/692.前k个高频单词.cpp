/*
 * @lc app=leetcode.cn id=692 lang=cpp
 *
 * [692] 前K个高频单词
 */
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> count;        
        for(const string& word : words)
            ++count[word];
        
        typedef pair<string, int> Node;

        auto comp = [](const Node& a, const Node& b)
        {
            if(a.second == b.second)
                return a.first < b.first;
            return a.second > b.second;
        };

        priority_queue<Node, vector<Node>, decltype(comp)> q(comp);

        for(const auto& kv : count)
        {
            q.push(kv);
            if(q.size() > k)
                q.pop();
        }

        vector<string> ans;
        while(!q.empty())
        {
            ans.push_back(q.top().first);
            q.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

