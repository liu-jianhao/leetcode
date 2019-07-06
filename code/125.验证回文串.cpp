/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */
class Solution {
public:
    bool isPalindrome(string s) {
        if(s.size() <= 1) return true;
        int i = 0, j = s.size() - 1;
        while(i < j){
            while(i < j && !isalnum(s[i])) // 排除所有非字母或数字的字符
                i++;
            while(i < j && !isalnum(s[j]))
                j--;
            if(tolower(s[i++]) != tolower(s[j--])) //统一转换成小写字母再比较
                return false;
        }
        return true;
    }
};

