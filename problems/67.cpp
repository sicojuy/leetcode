#include <string>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;
        int k = i > j ? i + 1 : j + 1;
        string ans(k + 1, '0');
        int p = 0;
        int n;
        while (i >= 0 && j >= 0) {
            n = a[i] - '0' + b[j] - '0' + p;
            p = n / 2;
            ans[k--] = '0' + n % 2;
            i--;
            j--;
        }
        while (i >= 0) {
            n = a[i] - '0' + p;            
            p = n / 2;
            ans[k--] = '0' + n % 2;
            i--;
        }
        while (j >= 0) {
            n = b[j] - '0' + p;
            p = n / 2;
            ans[k--] = '0' + n % 2;
            j--;
        }
        if (p > 0) {
            ans[k] = '1'; 
            return ans;
        } else {
            return ans.substr(1);
        }
    }
};