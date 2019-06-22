/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.rbegin(), coins.rend());    
        int res = INT_MAX;
        coinChange(res, coins, amount, 0, 0);
        return res == INT_MAX ? -1 : res;
    }

    void coinChange(int& res, vector<int>& coins, int amount, int index, int count)
    {
        const int coin = coins[index];

        if(index == coins.size()-1)
        {
            if(amount % coin == 0)
            {
                res = min(res, count + amount / coin);
            }
        }
        else 
        {
            for(int i = amount / coin; i >= 0 && count + i < res; --i)
            {
                coinChange(res, coins, amount - i * coin, index+1, count + i);
            }
        }
    }
};

