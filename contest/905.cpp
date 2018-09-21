#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> result;
        int k = 0;
        if (A.empty()) return result;
        result.resize(A.size());
        for (int i = 0; i < A.size(); i++) {
            if (A[i] % 2 == 0) {
                result[k++] = A[i];
            }
        }
        for (int i = 0; i < A.size(); i++) {
            if (A[i] % 2 == 1) {
                result[k++] = A[i];
            }
        }
        return result;
    }
};