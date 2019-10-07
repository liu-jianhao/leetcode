/*
 * @lc app=leetcode.cn id=136 lang=rust
 *
 * [136] 只出现一次的数字
 */

// @lc code=start
impl Solution {
    pub fn single_number(nums: Vec<i32>) -> i32 {
        let mut res = nums[0];
        for (i, n) in nums.iter().enumerate() {
            if i == 0 {
                continue
            }
            res ^= n
        }
        return res
    }
}
// @lc code=end

