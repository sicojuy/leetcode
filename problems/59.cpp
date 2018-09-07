#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result;
        int l, r;
        int i, c;
        result.resize(n);
        for (i = 0; i < n; i++) {
            result[i].resize(n);
        }
        c = 1;
        for (l = 0, r = n - 1; l < r; l++, r--) {
            for (i = l; i < r; i++) {
                result[l][i] = c++; 
            }
            for (i = l; i < r; i++) {
                result[i][r] = c++; 
            }
            for (i = r; i > l; i--) {
                result[r][i] = c++; 
            }
            for (i = r; i > l; i--) {
                result[i][l] = c++; 
            }
        }
        if (l == r) {
            result[l][r] = c;
        }
        return result;
    }
};