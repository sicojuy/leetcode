#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int len = s.length();
        int r = 0;
        for (int i = 0; i < len; i++) {
            if (s[i] == 'I') {
                if (i + 1 < len && (s[i+1] == 'V' || s[i+1] == 'X')) {
                    r -= 1;
                } else {
                    r += 1;
                }
            } else if (s[i] == 'V') {
                r += 5;
            } else if (s[i] == 'X') {
                if (i + 1 < len && (s[i+1] == 'L' || s[i+1] == 'C')) {
                    r -= 10;
                } else {
                    r += 10;
                }
            } else if (s[i] == 'L') {
                r += 50;
            } else if (s[i] == 'C') {
                if (i + 1 < len && (s[i+1] == 'D' || s[i+1] == 'M')) {
                    r -= 100;
                } else {
                    r += 100;
                }
            } else if (s[i] == 'D') {
                r += 500;
            } else {
                r += 1000;
            }
        }
        return r;
    }
};

int main() {
    Solution s;
    cout << s.romanToInt("MCMXCIV") << endl;
    return 0;
}