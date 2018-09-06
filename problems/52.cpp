#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    void nQueues(int *result, vector<int> &col, vector<int> &h1, vector<int> &h2, int m, int n) {
        int i;
        if (m == n) {
            *result += 1;
            return;
        }
        for (i = 0; i < n; i++) {
            if (col[i] == 1 || h1[m+i] == 1 || h2[m-i+n-1] == 1) continue;
            col[i] = 1;
            h1[m + i] = 1;
            h2[m-i+n-1] = 1;
            nQueues(result, col, h1, h2, m+1, n);
            col[i] = 0;
            h1[m + i] = 0;
            h2[m-i+n-1] = 0;
        }
    }

    int totalNQueens(int n) {
        int result = 0;
        vector<int> col(n);
        vector<int> h1(n*2-1);
        vector<int> h2(n*2-1);
        for (int i = 0; i < n; i++) {
            col[i] = 0;
            h1[i*2] = 0;
            h1[i*2+1] = 0;
            h2[i*2] = 0;
            h2[i*2+1] = 0;
        }
        nQueues(&result, col, h1, h2, 0, n);
        return result;
    }
};

int main() {
    Solution s;
    auto r = s.totalNQueens(8);
    cout << r << endl;
    return 0;
}