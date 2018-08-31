#include <vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int target = nums.size() - 1;
        int ans = 0;
        int prev, cur, next;
        int i;
        prev = cur = next = 0;
        while (next < target) {
            for (i = prev; i <= cur; i++) {
                if (i + nums[i] > next) next = i + nums[i];
            }
            prev = cur + 1;
            cur = next;
            ans++;
        }
        return ans;
    }
};