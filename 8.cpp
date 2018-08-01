#include <climits>
#include <string>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int len = str.length();
        int i;
        int res;
        int sign;
        i = 0;
        while (i < len && str[i] == ' ') i++;
        sign = 1;
        if (str[i] == '-') {
            sign = -1;
            i++;
        } else if (str[i] == '+') {
            i++;
        }
        res = 0;
        while (i < len && str[i] >= '0' && str[i] <= '9') {
            if (res != res * 10 / 10) return sign > 0 ? INT_MAX : INT_MIN;
            res = res * 10 + str[i] - '0';
            if (res < 0) return sign > 0 ? INT_MAX : INT_MIN;
            i++;
        }
        return sign * res;
    }
};