/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_multiset<char> ms1(s.begin(), s.end()), ms2(t.begin(), t.end());
        return ms1 == ms2;
    }
};

