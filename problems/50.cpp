class Solution {
public:
    double myPow(double x, int n) {
        double ans, t;
        bool neg = false;
        long long ln = n;
        if (ln < 0) {
            ln = 0 - ln;
            neg = true;
        }
    
        ans = 1.0;
        t = x;
        while (ln > 0) {
            if (ln & 1) {
                ans = ans * t;
            }
            t = t * t;
            ln = ln >> 1;
        }

        return neg ? 1.0 / ans : ans;
    }
};