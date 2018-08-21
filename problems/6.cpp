#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        int period, step1, step2;
        int i, j, k;
        int len = s.length();
        string result;

        if (numRows == 1) {
            return s;
        }

        result.resize(s.size());
        period = numRows + numRows - 2;
        step1 = period;
        step2 = 0;
        k = 0;
        for (i = 0; i < len; i += period) {
            result[k++] = s[i];
        }
        for (i = 1; i < numRows - 1; i++) {
            step1 -= 2;
            step2 += 2;
            j = i;
            while (true) {
                if (j < len) {
                    result[k++] = s[j];
                } else {
                    break;
                }
                j = j + step1;
                if (j < len) {
                    result[k++] = s[j]; 
                } else {
                    break;
                }
                j = j + step2;
            }
        }
        for (i = numRows - 1; i < len; i+= period) {
            result[k++] = s[i];
        }
        return result;
    }
};