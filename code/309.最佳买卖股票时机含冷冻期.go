/*
给定一个整数数组，其中第 i 个元素代表了第 i 天的股票价格 。​

设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:

你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。

示例:
输入: [1,2,3,0,2]
输出: 3 
解释: 对应的交易状态为: [买入, 卖出, 冷冻期, 买入, 卖出]
*/

func maxProfit(prices []int) int {
    if len(prices) <= 0 {
        return 0
    }
    dp := make([][]int, 2)
    // 当天没有持有股票
    dp1 := make([]int, len(prices))
    // 当天持有股票
    dp2 := make([]int, len(prices))
    dp[0] = dp1
    dp[1] = dp2

    // 初始值
    dp[0][0] = 0
    dp[1][0] = 0 - prices[0]

    for i, p := range prices {
        if i >= 1 {
            dp[0][i] = max(dp[0][i-1], dp[1][i-1] + p)
            if i >= 2 {
                dp[1][i] = max(dp[1][i-1], dp[0][i-2] - p)
            } else {
                dp[1][i] = max(dp[1][i-1], 0 - p)
            }
        }
    }

    return max(dp[0][len(prices)-1], dp[1][len(prices)-1])
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}