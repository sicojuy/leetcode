#include <vector>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i, j, k, len;
        nums.push_back(0);
        len = nums.size();
        for (i = 0; i < len; i++) {
            if (nums[i] == 0 || nums[i] == i) continue;
            j = nums[i];
            nums[i] = 0;
            while (j > 0 && j < len && nums[j] != j) {
                k = nums[j];
                nums[j] = j;
                j = k;
            }
        }
        for (i = 1; i < len; i++) {
            if (nums[i] == 0) {
                return i;
            }
        }
        return len;
    }
};