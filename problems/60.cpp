#include <string>
#include <sstream>
#include <iostream>
using namespace std;

class Solution {
public:
    int _getPermutation(int used[], int n, int k) {
        int period, len, num;
        int i, j;
        for (i = 1, len = 1, period = 1; i < n; i++) {
            len *= 10;
            period *= i;
        }
        for (i = 1, j = 0; i < 10; i++) {
            if (used[i] == 0) {
                j++;
            }
            if (j == (k - 1) / period + 1) {
                used[i] = 1;
                num = i;
                break;
            }
        }
        if (n == 1) {
            return num;
        }
        return num * len + _getPermutation(used, n-1, k-(j-1)*period);
    }

    string getPermutation(int n, int k) {
        stringstream stream;
        int used[10] = {0};
        stream << _getPermutation(used, n, k);
        return stream.str();
    }
};

int main() {
    Solution s;
    cout << s.getPermutation(3, 5) << endl;
    return 0;
}