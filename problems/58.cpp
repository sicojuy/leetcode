#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.length() - 1;
        int start, end;
        for (end = s.length() - 1; end >= 0; end--) {
            if (s[end] != ' ') break;
        }
        if (end < 0) return 0;
        for (start = end; start >= 0; start--) {
            if (s[start] == ' ') break;
        }
        return end - start;
    }
};