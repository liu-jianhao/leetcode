/*
 * @lc app=leetcode.cn id=1108 lang=rust
 *
 * [1108] IP 地址无效化
 */

// @lc code=start
impl Solution {
    pub fn defang_i_paddr(address: String) -> String {
        return address.replace(".", "[.]");
    }
}
// @lc code=end

