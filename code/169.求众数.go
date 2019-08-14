/*
 * @lc app=leetcode.cn id=169 lang=golang
 *
 * [169] 求众数
 */
func majorityElement(nums []int) int {
	count := 0
	maj := nums[0]
	for _, n := range nums {
		if n == maj {
			count += 1
		} else {
			count -= 1
			if count == 0 {
				maj = n
				count = 1
			}
		}
	}
	return maj
}

