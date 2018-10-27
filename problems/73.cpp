#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int i, j;
        bool r0, c0;
        r0 = c0 = false;
        for (i = 0; i < matrix.size(); i++) {
            if (matrix[i][0] == 0) {
                c0 = true;
                break; 
            } 
        }
        for (j = 0; j < matrix[0].size(); j++) {
            if (matrix[0][j] == 0) {
                r0 = true;
                break;
            }
        }
        for (i = 1; i < matrix.size(); i++) {
            for (j = 1; j < matrix[i].size(); j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (i = 1; i < matrix.size(); i++) {
            if (matrix[i][0] == 0) {
                for (j = 1; j < matrix[i].size(); j++) {
                    matrix[i][j] = 0;
                }
            }
        }
        for (j = 1; j < matrix[0].size(); j++) {
            if (matrix[0][j] == 0) {
                for (i = 1; i < matrix.size(); i++) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (r0 == true) {
            for (j = 0; j < matrix[0].size(); j++) {
                matrix[0][j] = 0;
            }
        }
        if (c0 == true) {
            for (i = 0; i < matrix.size(); i++) {
                matrix[i][0] = 0;
            }
        }
    }
};