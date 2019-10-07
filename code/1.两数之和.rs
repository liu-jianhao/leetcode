/*
 * @lc app=leetcode.cn id=1 lang=rust
 *
 * [1] 两数之和
 */

// @lc code=start
use std::collections::HashMap;
impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut ret: Vec<i32> = vec![0, 0];
        let mut map = HashMap::new();
        for i in 0..nums.len() {
            match map.get(&(target - nums[i])) {
                None => { map.insert(nums[i], i); }
                Some(index) => {
                    ret[0] = *index as i32;
                    ret[1] = i as i32;
                }
            }
        }
        return ret
    }
}
// @lc code=end

