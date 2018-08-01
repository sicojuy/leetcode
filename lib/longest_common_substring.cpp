#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string longestCommonSubstring(string& s1, string& s2)
{
    int i, j;
    int g[2][s2.length() + 1];
    int r0, r1;
    int substrIndex, substrLen;

    if (s1.empty() || s2.empty()) {
        return "";
    }

    for (i = 0; i <= s2.length(); i++) {
        g[0][i] = g[1][i] = 0;
    }

    r0 = 0;
    r1 = 1;
    substrIndex = substrLen = 0;
    for (i = 0; i < s1.length(); i++) {
        for (j = 0; j < s2.length(); j++) {
            if (s1[i] == s2[j]) {
                g[r1][j+1] = g[r0][j] + 1;
                if (g[r1][j+1] > substrLen) {
                    substrLen = g[r1][j+1];
                    substrIndex = j + 1 - substrLen;
                }
            } else {
                g[r1][j+1] = 0;
            }
        }
        swap(r0, r1);
    }

    return s2.substr(substrIndex, substrLen);
}

int main()
{
    string s1 = "abcdefgx";
    string s2 = "aacdefgy";
    cout << longestCommonSubstring(s1, s2) << endl;
    return 0;
}