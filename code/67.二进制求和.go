/*
 * @lc app=leetcode.cn id=67 lang=golang
 *
 * [67] 二进制求和
 */

// @lc code=start
func addBinary(a string, b string) string {
    i, j := len(a)-1, len(b)-1
	res := ""
	flag := 0 //进位标识
	for i >= 0 || j >= 0 {
		intA, intB := 0, 0
		if i >= 0 {
			intA = int(a[i] - '0')
		}
		if j >= 0 {
			intB = int(b[j] - '0')
		}
		sum:=intA+intB+flag
		switch sum {
		case 3: flag = 1; res = "1" + res
		case 2: flag = 1; res = "0" + res
		case 1: flag = 0; res = "1" + res
		case 0: flag = 0; res = "0" + res
		}
		i--
		j--
	}
	if flag == 1 {
		res = "1" + res
	}
	return res
}
// @lc code=end

