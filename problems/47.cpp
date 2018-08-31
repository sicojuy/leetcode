#include <vector>
using namespace std;

class Solution {
public:
    void _permuteUnique(vector<vector<int>>& result, vector<int>& nums, int x) {
        int i, j;
        if (x + 1 == nums.size()) {
            result.push_back(nums);
            return;
        }
        _permuteUnique(result, nums, x + 1);    
        for (i = x + 1; i < nums.size(); i++) {
            for (j = x; j < i; j++) {
                if (nums[i] == nums[j]) break;
            }
            if (j < i) continue;
            swap(nums[x], nums[i]);
            _permuteUnique(result, nums, x + 1);    
            swap(nums[x], nums[i]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;    
        _permuteUnique(result, nums, 0);
        return result;
    }
};