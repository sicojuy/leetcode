#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int offset = 0;
        int ans = 1;
        if (nums.empty()) return 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i-1]) {
                offset++;
            } else {
                ans++;
                nums[i-offset] = nums[i];
            }
        }
        nums.resize(nums.size() - offset);
        return ans;
    }
};