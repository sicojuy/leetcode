class Solution {
public:
    int mySqrt(int x) {
        int l, r, m;        
        if (x == 0) return 0;
        l = 1;
        r = x > 46340 ? 46340 : x;
        while (l + 1 < r) {
            m = (l + r) / 2;
            if (m * m > x) {
                r = m - 1;
            } else if (m * m < x) {
                l = m;
            } else {
                return m;
            }
        }
        if (r * r <= x) return r;
        return l;
    }
};