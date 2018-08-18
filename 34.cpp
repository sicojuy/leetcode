#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2);
        int start, end;
        int l, r, m;
        ans[0] = ans[1] = -1;
        l = 0;
        r = nums.size() - 1;
        while (l <= r) {
            m = (l + r) / 2;
            if (nums[m] == target) {
                if (m == l || nums[m-1] < target) {
                    ans[0] = m;
                    break;
                }
                r = m - 1;
            } else if (nums[m] > target) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        if (l > r) {
            return ans;
        }
        l = 0;
        r = nums.size() - 1;
        while (l <= r) {
            m = (l + r) / 2;
            if (nums[m] == target) {
                if (m == r || nums[m+1] > target) {
                    ans[1] = m;
                    break;
                }
                l = m + 1;
            } else if (nums[m] > target) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return ans;
    }
};