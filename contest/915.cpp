#include <vector>
using namespace std;

class Solution {
public:
    int partitionDisjoint(vector<int>& A) {
        int max1, max2;
        int pos = 0;
        max1 = max2 = A[0];
        for (int i = 1; i < A.size(); i++) {
            if (A[i] > max2) max2 = A[i];
            if (A[i] < max1) {
                max1 = max2;
                pos = i;
            }
        }
        return pos+1;
    }
};