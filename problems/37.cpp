#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int solve(vector<vector<char>>& board, int marks[3][10][10], int i, int j) {
        int k, n;
        while (i < 9) {
            while (j < 9) {
                if (board[i][j] == '.') break;
                j++;
            }
            if (board[i][j] == '.') break;
            i++;
            j = 0;
        }
        if (i == 9) return 0;
        for (n = 1; n < 10; n++) {
            k = i / 3 * 3 + j / 3;
            if (marks[0][i][n] == 1 || marks[1][j][n] == 1 || marks[2][k][n] == 1) continue;
            marks[0][i][n] = marks[1][j][n] = marks[2][k][n] = 1;
            board[i][j] = '0' + n;
            if (solve(board, marks, i, j) != -1) return 0;
            marks[0][i][n] = marks[1][j][n] = marks[2][k][n] = 0;
            board[i][j] = '.';
        }
        return -1;
    }

    void solveSudoku(vector<vector<char>>& board) {
        int marks[3][10][10] = {0};
        int i, j, k, n;
        for (i = 0; i < 9; i++) {
            for (j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                n = board[i][j] - '0';
                k = i / 3 * 3 + j / 3;
                marks[0][i][n] = marks[1][j][n] = marks[2][k][n] = 1;
            }
        }
        solve(board, marks, 0, 0);
    }
};