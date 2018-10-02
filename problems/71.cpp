#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        string result;
        stack<string> st;
        string s;
        int i, j;
        i = 0;
        while (i < path.length()) {
            j = path.find('/', i);
            if (j == i) {
                i = j + 1;
                continue;
            }
            
            if (j == string::npos) {
                s = path.substr(i);
            } else {
                s = path.substr(i, j-i);
            }
            
            if (s == ".") {
            } else if (s == "..") {
                if (!st.empty()) st.pop();
            } else {
                st.push(s);
            }
            
            if (j == string::npos) break;
            i = j + 1;
        }
        
        if (st.empty()) return "/";
        
        result = st.top();
        st.pop();
        while (!st.empty()) {
            result = st.top() + "/" + result;
            st.pop();
        }
        
        return "/" + result;
    }
};