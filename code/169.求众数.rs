/*
 * @lc app=leetcode.cn id=169 lang=rust
 *
 * [169] 求众数
 */
impl Solution {
    pub fn majority_element(nums: Vec<i32>) -> i32 {
        let mut count = 0;
        let mut maj = nums[0];
        for i in 0..nums.len() {
            if maj == nums[i] {
                count += 1;
            } else {
                count -= 1;
                if count == 0 {
                    maj = nums[i];
                    count = 1;
                }
            }
        }
        return maj;
    }
}

