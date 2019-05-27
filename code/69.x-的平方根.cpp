/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 */
class Solution {
public:
    int mySqrt(int x) {
        if(x == 0 || x == 1)
            return x;
        int low = 0, high = x, mid;
        while(low <= high)
        {
            mid = (low + high) / 2;
            if(mid == x / mid)
                return mid;
            else if(mid < x / mid && (mid+1) > x / (mid+1))
                return mid;
            else if(mid < x / mid)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return mid;
    }
};

