#include <string>
#include <vector>
#include <sstream>
#include <iostream>
using namespace std;

class Solution {
    vector<string> nums;
    int len;
public:
    Solution() {
        nums.push_back("1");
        len = 1;
    }

    string countAndSay(int n) {
        if (n <= len) return nums[n-1];
        int i, j;
        string s;
        stringstream next;
        int c;
        for (i = len - 1; i < n; i++) {
            next.str("");
            s = nums[i];
            c = 1;
            for (j = 1; j < s.size(); j++) {
                if (s[j] != s[j-1]) {
                    next << c << s[j-1];
                    c = 1;
                } else {
                    c++;
                }
            }
            next << c << s[j-1];
            nums.push_back(next.str());
        }
        len = n;
        return nums[n-1];
    }
};