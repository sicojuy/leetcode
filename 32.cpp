#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<char> p;
        stack<int> l;
        int x;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || p.empty() || p.top() == ')') {
                p.push(s[i]);
                l.push(0);
            } else {
                p.pop();
                if (l.top() == 0) {
                    x = 2;
                    l.pop();
                } else {
                    x = l.top() + 2;
                    l.pop();
                    l.pop();
                }
                if (!l.empty() && l.top() != 0) {
                    x += l.top();
                    l.pop();
                }
                l.push(x);
            }
        }
        x = 0;
        while (!l.empty()) {
            if (l.top() > x) {
                x = l.top();
            }
            l.pop();
        }
        return x;
    }
};