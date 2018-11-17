#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class Solution {
public:
    int shortestBridge(vector<vector<int>>& A) {
        queue<int> q;
        queue<int> qq;
        int i, j, ii, jj;
        int direct[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int k;
        int len = A.size();
        k = findOne(A, len);
        if (k == -1) return -1;
        q.push(k);
        qq.push(k);
        while (!q.empty()) {
            k = q.front();
            q.pop();
            i = k / 10000;
            j = k % 10000;
            for (k = 0; k < 4; k++) {
                ii = i + direct[k][0];
                jj = j + direct[k][1];
                if (ii < 0 || ii >= len || jj < 0 || jj >= len) continue;
                if (A[ii][jj] == 1) {
                    A[ii][jj] = -1;
                    q.push(ii * 10000 + jj);
                    qq.push(ii * 10000 + jj);
                }
            }
        }
        while (!qq.empty()) {
            k = qq.front();
            qq.pop();
            i = k / 10000;
            j = k % 10000;
            for (k = 0; k < 4; k++) {
                ii = i + direct[k][0];
                jj = j + direct[k][1];
                if (ii < 0 || ii >= len || jj < 0 || jj >= len) continue;
                if (A[ii][jj] == 1) return -1 - A[i][j];
                if (A[ii][jj] == 0) {
                    A[ii][jj] = A[i][j] - 1;
                    qq.push(ii * 10000 + jj);
                }
            }
        }
        return -1;
    }

    int findOne(vector<vector<int>>& A, int len) {
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
                if (A[i][j] == 1) {
                    A[i][j] = -1;
                    return i * 10000 + j;
                }
            }
        }
        return -1;
    }
};
