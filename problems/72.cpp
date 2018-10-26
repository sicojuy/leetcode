#include <string>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int l1 = word1.size();
        int l2 = word2.size();
        int dp[l1+1][l2+1];
        int i, j;
        dp[0][0] = 0;
        for (i = 1; i <= l1; i++) {
            dp[i][0] = i;
        }
        for (j = 1; j <= l2; j++) {
            dp[0][j] = j;
        }
        for (i = 1; i <= l1; i++) {
            for (j = 1; j <= l2; j++) {
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = min3(dp[i-1][j-1], dp[i-1][j]+1, dp[i][j-1]+1);
                } else {
                    dp[i][j] = min3(dp[i-1][j-1]+1, dp[i-1][j]+1, dp[i][j-1]+1);
                }
            }
        }
        return dp[l1][l2];
    }
    
    int min3(int x, int y, int z) {
        return min(x, min(y, z));
    }
};