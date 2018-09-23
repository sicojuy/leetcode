#include <vector>
using namespace std;

class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        int max, min;
        max = min = A[0];
        for (int i = 1; i < A.size(); i++) {
            if (max < A[i]) max = A[i];
            if (min > A[i]) min = A[i];
        }
        return max - min > 2 * K ? max - min - 2 * K : 0;
    }
};