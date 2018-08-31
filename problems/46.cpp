#include <vector>
using namespace std;

class Solution {
public:
    void _permute(vector<vector<int>>& result, vector<int>& nums, int x) {
        int i;
        if (x + 1 == nums.size()) {
            result.push_back(nums);
            return;
        }
        for (i = x; i < nums.size(); i++) {
            swap(nums[x], nums[i]);
            _permute(result, nums, x + 1);    
            swap(nums[x], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;    
        _permute(result, nums, 0);
        return result;
    }
};