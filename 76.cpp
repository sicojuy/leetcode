#include <string>
#include <iostream>
using namespace std;

class Solution {
    int count;
public:
    string minWindow(string s, string t) {
        int sc[128] = {0};      
        int tc[128] = {0};      
        for (auto &c : s) {
            sc[c]++;
        }
        for (auto &c : t) {
            tc[c]++;
        }
        for (int i = 0; i < 128; i++) {
            if (tc[i] > sc[i]) {
                return "";
            }
        }
        count = 0;
        string ans = minWindow(s, sc, tc);
        cout << count << endl;
        return ans;
    }

    string minWindow(string s, int sc[], int tc[]) {
        count++;
        string s1, s2;
        int i, j;
        for (i = 0; i < s.length(); i++) {
            if (tc[s[i]] > 0) {
                break;
            }
        }
        for (j = s.length() - 1; j >= 0; j--) {
            if (tc[s[j]] > 0) {
                break;
            }
        }
        if (sc[s[i]] == tc[s[i]] && sc[s[j]] == tc[s[j]]) {
            return s.substr(i, j - i + 1);
        }
        if (sc[s[i]] == tc[s[i]]) {
            sc[s[j]]--;
            s1 = minWindow(s.substr(i, j-i), sc, tc);
            sc[s[j]]++;
            return s1;
        } else if (sc[s[j]] == tc[s[j]]) {
            sc[s[i]]--;
            s1 = minWindow(s.substr(i+1, j-i), sc, tc);
            sc[s[i]]++;
            return s1;
        } else {
            sc[s[j]]--;
            s1 = minWindow(s.substr(i, j-i), sc, tc);
            sc[s[j]]++;
            sc[s[i]]--;
            s2 = minWindow(s.substr(i+1, j-i), sc, tc);
            sc[s[i]]++;
            return s1.length() < s2.length() ? s1 : s2;
        }
    }
};

int main() {
    //string s = "ask_not_what_your_country_can_do_for_you_ask_what_you_can_do_for_your_country";
    string s = "ask_what_you_can_do_for_your_country";
    string t = "ask_country";
    Solution sol;
    cout << sol.minWindow(s, t) << endl;
}