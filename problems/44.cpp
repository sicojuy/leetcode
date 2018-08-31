#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int i, j, k, l;

        if (p.size() == 0) return s.size() == 0;

        if (p[0] != '*') {
            i = 0;
            while (i < s.size() && i < p.size()) {
                if (p[i] == '*') {
                    return isMatch(s.substr(i), p.substr(i));
                }
                if (p[i] != '?' && p[i] != s[i]) {
                    return false;
                }
                i++;
            }
            if (i == p.size()) return i == s.size();
            return p.find_first_not_of('*', i) == string::npos;
        }

        i = 0;
        while (i < p.size() && p[i] == '*') i++;
        if (i == p.size()) return true;

        j = i;
        while (j < p.size() && p[j] != '*') j++;
        if (j - i > s.size()) return false;
        if (j == p.size()) return isMatch(s.substr(s.size() - j + i), p.substr(i));

        for (k = 0; k + j - i <= s.size(); k++) {
            for (l = k; l < k + j - i; l++) {
                if (p[i+l-k] != '?' && p[i+l-k] != s[l]) break;
            }
            if (l == k + j - i) {
                return isMatch(s.substr(k + j - i), p.substr(j));
            }
        }
        return false;
    }
};

int main() {
    string str("abce");
    string p("abc*??");
    Solution s;
    cout << s.isMatch(str, p) << endl;
    return 0;
}