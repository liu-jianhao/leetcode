/*
 * @lc app=leetcode.cn id=1004 lang=rust
 *
 * [1004] 最大连续1的个数 III
 */
impl Solution {
    pub fn longest_ones(a: Vec<i32>, k: i32) -> i32 {
        let mut res = 0;
        let mut count = 0;
        let mut l = 0;
        for r in 0..a.len() {
            if a[r] == 1 {
                count = count + 1
            }
            while r - l + 1 - count > k as usize {
                if a[l] == 1 {
                    count = count - 1
                }
                l = l + 1
            }
            if res < r - l + 1 {
                res = r - l + 1
            }
        }
        return res as i32
    }
}

