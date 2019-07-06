/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */
class Solution {
public:
    bool isValid(string s) {
        if(s.empty())
            return true;

        unordered_map<char, char> map{{'(',')'}, {'[',']'}, {'{','}'}};
        stack<char> stack;
        for(char c : s)
        {
            auto it = map.find(c);
            if(it != map.end())
                stack.push(c);
            else
                if(stack.empty() || map[stack.top()] != c)
                    return false;
                else
                    stack.pop();
        }
        return stack.empty();
    }
};

