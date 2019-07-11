/*
 * @lc app=leetcode.cn id=901 lang=cpp
 *
 * [901] 股票价格跨度
 */
class StockSpanner {
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        if(_i == 0 || price < _prices.back())
        {
            _dp.push_back(1);
        }
        else
        {
            int j = _i - 1;
            while(j >= 0 && price >= _prices[j])
            {
                j -= _dp[j];
            }
            _dp.push_back(_i - j);
        }
        ++_i;
        _prices.push_back(price);        
        return _dp.back();
    }

private:
    vector<int> _dp;
    vector<int> _prices;
    int _i = 0;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

