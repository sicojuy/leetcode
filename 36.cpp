#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool m[10];
        int i, j, k;
        char c;
        for (i = 0; i < 9; i++) {
            for (j = 0; j < 10; j++) m[j] = false;
            for (j = 0; j < 9; j++) {
                c = board[i][j];
                if (c == '.') continue;
                k = c - '0';
                if (m[k]) return false;
                m[k] = true;
            }
        }
        cout << "col" << endl;
        for (i = 0; i < 9; i++) {
            for (j = 0; j < 10; j++) m[j] = false;
            for (j = 0; j < 9; j++) {
                c = board[j][i];
                if (c == '.') continue;
                k = c - '0';
                if (m[k]) return false;
                m[k] = true;
            }
        }
        cout << "grid" << endl;
        for (i = 0; i < 9; i++) {
            for (j = 0; j < 10; j++) m[j] = false;
            for (j = 0; j < 9; j++) {
                c = board[i / 3 * 3 + j / 3][i % 3 * 3 + j % 3];
                if (c == '.') continue;
                k = c - '0';
                if (m[k]) return false;
                m[k] = true;
            }
        }
        return true;
    }
};

int main() {
    int x[9][9];
    int c = 0;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            x[i/3*3+j/3][i%3*3+j%3] = c++;
        }
    }
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << x[i][j] << " ";
        }
        cout << endl;
    }
}