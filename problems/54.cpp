#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int l, r, u, d;
        int i, j;
        if (matrix.size() == 0) return result;
        result.resize(matrix.size() * matrix[0].size());
        i = 0;
        for (l = u = 0, r = matrix[0].size() - 1, d = matrix.size() - 1; l < r && u < d; l++, r--, u++, d--) {
            for (j = l; j < r; j++) {
                result[i++] = matrix[u][j];
            }            
            for (j = u; j < d; j++) {
                result[i++] = matrix[j][r];
            }
            for (j = r; j > l; j--) {
                result[i++] = matrix[d][j];
            }
            for (j = d; j > u; j--) {
                result[i++] = matrix[j][l];
            }
        }
        if (l == r) {
            for (j = u; j <= d; j++) {
                result[i++] = matrix[j][l];
            }
        } else if (u == d) {
            for (j = l; j <= r; j++) {
                result[i++] = matrix[u][j];
            }
        }
        return result;
    }
};

int main() {
    vector<vector<int>> matrix;
    matrix.push_back(vector<int>(1));
    matrix[0][0] = 5;
    Solution s;
    auto result = s.spiralOrder(matrix);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << ", ";
    }
    cout << endl;
    return 0;
}
