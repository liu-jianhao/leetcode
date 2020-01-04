/*
 * @lc app=leetcode.cn id=279 lang=rust
 *
 * [279] 完全平方数
 */

// @lc code=start
use std::cmp::min;
impl Solution {
    pub fn num_squares(n: i32) -> i32 {
        let mut dp = vec![n; n as usize + 1];
        dp[0] = 0;
        for i in 1..=n as usize {
            let mut j = 1 as usize;
            dp[i] = i as i32;
            while i >= j*j {
                dp[i] = min(dp[i], dp[i-j*j] + 1);
                j += 1;
            }
        }
        dp[n as usize]
    }
}
// @lc code=end

