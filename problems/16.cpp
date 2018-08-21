#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int sum, diff, tmp;       
        int i, j, k;
        diff = INT_MAX;
        sort(nums.begin(), nums.end());
        for (i = 0; i < nums.size() && diff > 0; i++) {
            if (nums[i] >= 0 && nums[i] - target > diff) break;
            if (i > 0 && nums[i] == nums[i-1]) continue;
            j = i + 1;
            k = nums.size() - 1;
            while (j < k) {
                tmp = nums[i] + nums[j] + nums[k];
                if (abs(tmp - target) < diff) {
                    diff = abs(tmp - target);
                    sum = tmp;
                }
                if (tmp < target) j++;
                else k--;
            }
        }
        return sum;
    }
};