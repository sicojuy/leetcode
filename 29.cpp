#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        int rDividend = 0;
        int bitLen = 0;
        int quotient = 0;
        int desidue = 0;
        int fix = 0;
        bool sign = dividend < 0 ? divisor >= 0 : divisor < 0;
        if (divisor == INT32_MIN) return dividend == INT32_MIN ? 1 : 0;
        if (dividend == INT32_MIN) {
            fix = 1;
            dividend++; 
        }
        if (dividend < 0) dividend = 0 - dividend;
        if (divisor < 0) divisor = 0 - divisor;
        if (dividend < divisor) return 0;
        while (dividend) {
            rDividend = rDividend << 1;
            rDividend = rDividend | (dividend & 1);
            dividend = dividend >> 1;
            bitLen++;
        }
        while (bitLen--) {
            desidue = desidue << 1;
            desidue = desidue | (rDividend & 1);
            rDividend = rDividend >> 1;
            quotient = quotient << 1;
            if (desidue >= divisor) {
                quotient += 1;
                desidue -= divisor;
            }
        }
        quotient = sign ? 0 - quotient : quotient;
        if (desidue + fix < divisor) {
            return quotient;
        }
        if (quotient < 0) {
            return quotient-1;
        } else if (quotient == INT32_MAX) {
            return INT32_MAX;
        } else {
            return quotient+1;
        }
    }
};

int main() {
    Solution s;
    int x = -2147483648;
    cout << s.divide(x, 1) << endl;
    return 0;
}