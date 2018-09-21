#include <string>
using namespace std;

class Solution {
public:
    string trim(string s) {
        int i, j; 
        for (i = 0; i < s.length(); i++) {
            if (s[i] != ' ') break;
        }
        for ( j = s.length() - 1; j >= 0; j--) {
            if (s[j] != ' ') break;
        }
        return s.substr(i, j - i + 1);
    }

    int nextNumber(string s, int i) {
        int j;
        bool p = false;
        if (s[i] == '-' || s[i] == '+') i++;
        for (j = i; j < s.length(); j++) {
            if (s[j] == '.') {
                if (p) break;
                else p = true;
            } else if (s[j] < '0' || s[j] > '9') {
                break;
            }
        }
        if (p) {
            return i + 1 == j ? -1 : j;
        } else {
            return i == j ? -1 : j;
        }
    }

    int nextInteger(string s, int i) {
        int j;
        if (s[i] == '-' || s[i] == '+') i++;
        for (j = i; j < s.length(); j++) {
            if (s[j] < '0' || s[j] > '9') break;
        }
        return i == j ? -1 : j;
    }

    bool isNumber(string s) {
        int i, j;
        s = trim(s);
        if (s.empty()) return false;
        j = nextNumber(s, 0);
        if (j == s.length()) return true;
        if (j == -1) return false;
        if (s[j] == 'e') {
            return nextInteger(s, j+1) == s.length();
        }
        return false;
    }
};