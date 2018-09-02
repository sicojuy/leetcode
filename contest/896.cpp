#include <vector>
using namespace std;

class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        if (A.size() < 2) return true;
        bool isInc;
        for (int i = 1; i < A.size(); i++) {
            if (A[i] != A[i-1]) isInc = A[i] > A[i-1];
        }
        if (isInc) {
            for (int i = 1; i < A.size(); i++) {
                if (A[i] < A[i-1]) {
                    return false;
                }
            }
        } else {
            for (int i = 1; i < A.size(); i++) {
                if (A[i] > A[i-1]) {
                    return false;
                }
            }
        }
        return true;
    }
};