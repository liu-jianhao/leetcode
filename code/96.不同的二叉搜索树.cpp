/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */
// 卡特兰数
// 假设n个节点存在二叉排序树的个数是G(n)，令f(i)为以i为根的二叉搜索树的个数，则
// G(n) = f(1) + f(2) + f(3) + f(4) + ... + f(n)G(n)=f(1)+f(2)+f(3)+f(4)+...+f(n)
// 当i为根节点时，其左子树节点个数为i-1个，右子树节点为n-i，则
// f(i) = G(i-1)*G(n-i)f(i)=G(i−1)∗G(n−i)
// 综合两个公式可以得到卡特兰数公式
// G(n) = G(0)*G(n-1)+G(1)*(n-2)+...+G(n-1)*G(0)G(n)=G(0)∗G(n−1)+G(1)∗(n−2)+...+G(n−1)∗G(0)
class Solution {
public:
    int numTrees(int n) {
        if(n <= 1)
            return 1;
        vector<int> dp(n+1);
        dp[0] = 1;
        dp[1] = 1;

        for(int i = 2; i < n+1; ++i)
            for(int j = 1; j < i+1; ++j)
                dp[i] += dp[j-1] * dp[i-j];
        
        return dp[n];
    }
};

