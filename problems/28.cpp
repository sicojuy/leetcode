#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int kmp(string s, string p) {
        vector<int> next(p.size());
        int i, j;
        int ns, np;
        ns = s.size();
        np = p.size();
        next[0] = -1;
        i = 0;
        j = -1;
        while (i < np - 1) {
            if (j == -1 || p[i] == p[j]) {
                i++;
                j++;
                next[i] = (p[i] != p[j]) ? j : next[j];
            } else {
                j = next[j];
            }
        }

        i = 0;
        j = 0;
        while (i < ns && j < np) {
            if (j == -1 || s[i] == p[j]) {
                i++;
                j++;
            } else {
                j = next[j];
            }
        }

        return j == np ? i - j : -1;
    }

    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        return kmp(haystack, needle);
    }
};

int main() {
    Solution s;
    cout << s.strStr("allo", "ll") << endl;
    return 0;
}