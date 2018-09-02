#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int i, j, k;
        i = 0;
        j = matrix.size() - 1;
        while (i < j) {
            for (k = i; k < j; k++) {
                swap(matrix[i][k], matrix[k][j]);
                swap(matrix[i][k], matrix[j][j-k+i]);
                swap(matrix[i][k], matrix[j-k+i][i]);
            }
            i++;
            j--;
        }
    }
};