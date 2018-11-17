#include <string>
#include <iostream>
using namespace std;

class Solution {
    int count;
public:
    string minWindow(string s, string t) {
        int sm[128] = {0};      
        int tm[128] = {0};
        int sc = 0;
        int tc = t.length();
        int i, j;
        string ans;

        if (tc == 0) return ans;

        for (auto &c : t) tm[c]++;

        i = j = 0;
        while (true) {
            while (j < s.length() && sc < tc) {
                if (tm[s[j]] == 0) {
                    j++;
                    continue;
                }
                if (sm[s[j]] < tm[s[j]]) {
                    sc++;
                }
                sm[s[j]]++;
                j++;
            }
            if (sc < tc) break;
            while (i < j && sc == tc) {
                if (tm[s[i]] == 0) {
                    i++;
                    continue;
                } 
                if (sm[s[i]] == tm[s[i]]) {
                    sc--;
                    if (ans.empty() || j - i < ans.length()) {
                        ans = s.substr(i, j - i);
                    }
                }
                sm[s[i]]--;
                i++;
            }
        }
        return ans;
    }
};