/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原IP地址
 */
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        string ip;
        helper(res, ip, s, 0, 0);
        return res;
    }

    void helper(vector<string>& res, string ip, string& s, int start, int partNum)
    {
        int len = s.size();
        if(len - start < 4 - partNum || len - start > 3 * (4 - partNum))
            return;

        if(partNum == 4 && start == len)
        {
            ip.pop_back();
            res.push_back(ip);
            return;
        }

        int num = 0;
        for(int i = start; i < start + 3; ++i)
        {
            num = num * 10 + s[i] - '0';
            if(num < 256)
            {
                ip += s[i];
                helper(res, ip+'.', s, i+1, partNum+1);
            }
            if(num == 0)
                break;
        }
    }
};

