#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen, curLen;
        unordered_map<char, bool> m;
        
        if (s.empty()) {
            return 0;
        }

        maxLen = curLen = 0;
        for (int i = 0; i < s.length(); i++) {
            if (m.find(s[i]) == m.end()) {
                curLen++;
            } else {
                if (curLen > maxLen) {
                    maxLen = curLen;
                }
                i = i - curLen + 1;
                curLen = 1;
                m.clear();
            }
            m[s[i]] = true;
        }
        if (curLen > maxLen) {
            maxLen = curLen;
        }

        return maxLen;
    }
};