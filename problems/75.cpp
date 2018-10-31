#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int r, w, b;
        for (r = -1, w = 0, b = nums.size(); w < b; w++) {
            if (nums[w] == 0) {
                r++;
                if (r < w) {
                    swap(nums[r], nums[w]);
                }
            } else if (nums[w] == 2) {
                b--;
                if (b > w) {
                    swap(nums[b], nums[w]);
                    w--;
                }
            }
        }
    }
};