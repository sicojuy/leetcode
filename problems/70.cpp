class Solution {
public:
    int climbStairs(int n) {
        if (n < 2) return 1;
        int dp0, dp1, dp;
        dp0 = dp1 = 1;
        for (int i = 2; i <= n; i++) {
            dp = dp0 + dp1;
            dp0 = dp1;
            dp1 = dp;
        }
        return dp;
    }
};