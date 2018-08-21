#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.size() == 0) return s.size() == 0;
        
        bool match = false;
        if (s.size() > 0 && (p[0] == '.' || p[0] == s[0])) match = true;

        if (p.size() > 1 && p[1] == '*') {
            return isMatch(s, p.substr(2)) || (match && isMatch(s.substr(1), p));
        } else {
            return match && isMatch(s.substr(1), p.substr(1));
        }
    }
};