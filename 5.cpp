#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s)
    {
        int i, j, k;
        int lpIndex, lpLen;
        lpIndex = 0;
        lpLen = 1;
        for (i = 0; i + lpLen - 1 < s.length(); i++) {
            for (j = s.length() - 1; i + lpLen - 1 < j; j--) {
                for (k = 0; k < j - i; k++) {
                    if (s[i+k] != s[j-k]) {
                        break;
                    }
                }
                if (k == j - i && j - i + 1 > lpLen) {
                    lpIndex = i;
                    lpLen = j - i + 1;
                }
            }
        }
        return s.substr(lpIndex, lpLen);
    }
};