#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left, right, mid;
        int row, col;
        int i, j; 
        if (matrix.empty() || matrix[0].empty()) return false;
        row = matrix.size();
        col = matrix[0].size();
        left = 0;
        right = row * col - 1;
        while (left <= right) {
            mid = (left + right) / 2;
            i = mid / col;
            j = mid % col;
            if (matrix[i][j] == target) {
                return true;
            } else if (matrix[i][j] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return false;
    }
};