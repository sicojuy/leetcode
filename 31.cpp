#include <vector>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i, j, k;
        int len = nums.size();
        for (i = len - 1; i > 0; i--) {
            if (nums[i] > nums[i-1]) {
                break;
            }
        }
        for (j = i, k = len - 1; j < k; j++, k--) {
            swap(nums[j], nums[k]);
        }
        if (i == 0) {
            return;
        }
        i--;
        for (j = i + 1; j < len; j++) {
            if (nums[j] > nums[i]) {
                swap(nums[j], nums[i]);
                break;
            }
        }
    }
};