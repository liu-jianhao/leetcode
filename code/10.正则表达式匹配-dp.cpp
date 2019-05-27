/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */
class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<int>>results(p.size() + 1, vector<int>(s.size() + 1, 0));
		results[0][0] = 1;
		for (size_t i = 1; i <= p.size(); ++i) {
			results[i][0] = p[i - 1] == '*' ? results[i - 2][0] : 0;
			for (size_t j = 1; j <= s.size(); ++j) {
				if (p[i - 1] == '*') {
					if (s[j - 1] != p[i - 2] && p[i - 2] != '.') {
						results[i][j] = results[i - 2][j]; //相当于*一次都不用
					}
					else {
						results[i][j] = results[i - 2][j] || results[i - 1][j] || results[i][j - 1]; //*一次都不用或者用一次或者用多次
					}
				}
				else if (p[i - 1] == '.' || p[i - 1] == s[j - 1]) {
					results[i][j] = results[i - 1][j - 1]; // 逐个比较
				}
			}
		}
		return results[p.size()][s.size()];
    }
};

