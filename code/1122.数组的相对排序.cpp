/*
 * @lc app=leetcode.cn id=1122 lang=cpp
 *
 * [1122] 数组的相对排序
 */

// @lc code=start
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> map;
        vector<int> notIn;
        
        for(int a : arr2) {
            map[a] = 0;
        }

        for(int a : arr1) {
            if(map.count(a) > 0) {
                ++map[a];
            } else {
                notIn.push_back(a);
            }
        }
        sort(notIn.begin(), notIn.end());

        vector<int> res;
        for(int a : arr2) {
            for(int i = 0; i < map[a]; ++i) {
                res.push_back(a);
            }
        }

        for(int n : notIn) {
            res.push_back(n);
        }

        return res;
    }
};
// @lc code=end

