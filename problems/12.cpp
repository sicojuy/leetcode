#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string r;       
        string chars[] = {"MMM", "MM", "M", "CM", "DCCC", "DCC", "DC", "D", "CD", "CCC", "CC", "C", "XC", "LXXX", "LXX", "LX", "L",
                          "XL", "XXX", "XX", "X", "IX", "VIII", "VII", "VI", "V", "IV", "III", "II", "I"};
        int vals[] = {3000, 2000, 1000, 900, 800, 700, 600, 500, 400, 300, 200, 100, 90, 80, 70, 60, 50, 40, 30, 20, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
        int n = 30;
        for (int i = 0; i < n; i++) {
            if (num >= vals[i]) {
                r += chars[i];
                num -= vals[i];
            }
        }
        return r;
    }
};

int main() {
    Solution s;
    cout << s.intToRoman(1) << endl;
}