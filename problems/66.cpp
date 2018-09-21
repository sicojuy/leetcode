#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result(digits.size());
        int p = 1;
        for (int i = digits.size() - 1; i >= 0; i--) {
            result[i] = digits[i] + p; 
            if (result[i] == 10) {
                result[i] = 0;
                p = 1;
            } else {
                p = 0;
            }
        }
        if (p == 1) {
            result.push_back(1);
            for (int i = result.size() - 1; i > 0; i--) swap(result[i], result[i-1]);
        }
        return result;
    }
};