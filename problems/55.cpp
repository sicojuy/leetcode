#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i;
        int goal = nums.size() - 1;
        while (goal > 0) {
            for (i = goal - 1; i >= 0; i--) {
                if (i + nums[i] >= goal) {
                    goal = i;
                    break;
                }
            }
            if (i < 0) return false;
        }
        return true;
    }
};