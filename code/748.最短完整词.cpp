/*
 * @lc app=leetcode.cn id=748 lang=cpp
 *
 * [748] 最短完整词
 */
class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<int> l(26);
        for(char c : licensePlate)
        {
            if(isalpha(c))
                ++l[tolower(c) - 'a'];
        }

        string res;
        int min_l = INT_MAX;
        for(string word : words)
        {
            if(word.length() >= min_l)
                continue;
            if(!match(l, word))
                continue;
            min_l = word.length();
            res = word;
        }
        return res;
    }

private:
    bool match(const vector<int>& l, const string& word)
    {
        vector<int> c(26);
        for(char ch : word)
        {
            ++c[tolower(ch) - 'a'];
        }
        for(int i = 0; i < 26; ++i)
        {
            if(c[i] < l[i])
                return false;
        }
        return true;
    }
};

