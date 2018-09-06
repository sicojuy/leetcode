#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    void nQueues(vector<vector<string>> &result, vector<string> &grid, vector<int> &col, vector<int> &h1, vector<int> &h2, int m, int n) {
        int i;
        if (m == n) {
            result.push_back(grid);
            return;
        }
        for (i = 0; i < n; i++) {
            if (col[i] == 1 || h1[m+i] == 1 || h2[m-i+n-1] == 1) continue;
            col[i] = 1;
            h1[m + i] = 1;
            h2[m-i+n-1] = 1;
            grid[m][i] = 'Q';
            nQueues(result, grid, col, h1, h2, m+1, n);
            grid[m][i] = '.';
            col[i] = 0;
            h1[m + i] = 0;
            h2[m-i+n-1] = 0;
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> grid;
        vector<int> col(n);
        vector<int> h1(n*2-1);
        vector<int> h2(n*2-1);
        for (int i = 0; i < n; i++) {
            grid.push_back(string(n, '.'));
            col[i] = 0;
            h1[i*2] = 0;
            h1[i*2+1] = 0;
            h2[i*2] = 0;
            h2[i*2+1] = 0;
        }
        nQueues(result, grid, col, h1, h2, 0, n);
        return result;
    }
};

int main() {
    Solution s;
    auto r = s.solveNQueens(4);
    for (auto it = r.begin(); it != r.end(); it++) {
        for (auto it2 = it->begin(); it2 != it->end(); it2++) {
            cout << *it2 << endl;
        }
        cout << "=====" << endl;
    }
    return 0;
}