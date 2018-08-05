#include <vector>
using namespace std;

class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int ans = 0;
        int g[3][50][50] = {0};
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                for (int k = 0; k < grid[i][j]; k++) {
                    g[0][i][k] = 1;
                }
                for (int k = 0; k < grid[i][j]; k++) {
                    g[1][k][j] = 1;
                }
                if (grid[i][j] > 0) {
                    g[2][i][j] = 1;
                }
            }
        }
        for (int i = 0; i < 50; i++) {
            for (int j = 0; j < 50; j++) {
                for (int k = 0; k < 3; k++) {
                    ans += g[k][i][j];
                }
            }
        }
        return ans;
    }
};