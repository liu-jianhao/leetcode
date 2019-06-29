/*
 * @lc app=leetcode.cn id=71 lang=cpp
 *
 * [71] 简化路径
 */
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> tmpres;
        int i = 0;
        while(i < path.size())
        {
            while(path[i] == '/' && i < path.size())
                ++i;

            if(i == path.size())
                break;

            int start = i;
            while(path[i] != '/' && i < path.size())
                ++i;
            int end = i - 1;
            string s = path.substr(start, end - start + 1);
            
            if(s == "..")
            {
                if(!tmpres.empty())
                {
                    tmpres.pop_back();
                }
            }
            else if(s != ".")
            {
                tmpres.push_back(s);
            }
        }

        if(tmpres.empty())
            return "/";
        
        string res;
        for(string s : tmpres)
        {
            res += "/" + s;
        }
        return res;
    }
};

