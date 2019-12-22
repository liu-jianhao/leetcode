/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
class Solution {
public:
    int romanToInt(string s) {
        if(s.size() == 0) {
            return 0;
        }

        unordered_map<char, int> map;
        map['I'] = 1;
        map['V'] = 5;
        map['X'] = 10;
        map['L'] = 50;
        map['C'] = 100;
        map['D'] = 500;
        map['M'] = 1000;

        int res = 0;
        int tmp = 0;

        for(int i = 0; i < s.size(); ++i) {
             if(i+1 < s.size() && map[s[i]] < map[s[i+1]]) {
                 tmp = map[s[i+1]] - map[s[i]];
                 ++i;
             } else {
                 tmp = map[s[i]];
             }
             res += tmp;
        }

        return res;
    }
};
// @lc code=end

