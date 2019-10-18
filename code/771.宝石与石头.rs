/*
 * @lc app=leetcode.cn id=771 lang=rust
 *
 * [771] 宝石与石头
 */

// @lc code=start
use std::collections::HashMap;
impl Solution {
    pub fn num_jewels_in_stones(j: String, s: String) -> i32 {
        let mut map = HashMap::new();
        for c in j.chars() {
            map.insert(c, 1);
        }
        let mut count: i32 = 0;
        for c in s.chars() {
            match map.get(&(c)) {
                Some(n) => {
                    count = count + 1
                }
                None => {}
            }
        }
        count
    }
}
// @lc code=end

