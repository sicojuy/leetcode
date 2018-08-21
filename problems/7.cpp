class Solution {
public:
    int reverse(int x) {
        int sign;
        int y;
        if (x < 0) {
            sign = -1;
            x = -1 * x;
        } else {
            sign = 1;
        }
        y = 0;
        while (x) {
            if (y != y * 10 / 10) return 0;
            y = y * 10 + x % 10;
            if (y < 0) return 0;
            x = x / 10;
        }
        return sign * y;
    }
};