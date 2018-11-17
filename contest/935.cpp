#include <vector>
using namespace std;

class Solution {
public:
    int knightDialer(int N) {
        int go[][4] = {
            {2, 4, 6},
            {2, 6, 8},
            {2, 7, 9},
            {2, 4, 8},
            {3, 0, 3, 9},
            {0},
            {3, 0, 1, 7},
            {2, 2, 6},
            {2, 1, 3},
            {2, 2, 4},
        };
        int dp[10][N];
        int i, j, k;
        for (i = 0; i < 10; i++) {
            dp[i][0] = 1; 
        }
        for (j = 1; j < N; j++) {
            for (i = 0; i < 10; i++) {
                dp[i][j] = 0;
                for (k = 1; k <= go[i][0]; k++) {
                    dp[i][j] += dp[go[i][k]][j-1] % 1000000007;
                    dp[i][j] = dp[i][j] % 1000000007;
                }
            }
        }
        int ans = 0;
        for (i = 0; i < 10; i++) {
            ans += dp[i][N-1] % 1000000007;
            ans = ans % 1000000007;
        }
        return ans;
    }
};