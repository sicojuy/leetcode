#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> result;
        for (size_t i = 0; i < nums.size(); i++) {
            if (m.count(target - nums[i]) > 0) {
                result.push_back(m[target-nums[i]]); 
                result.push_back(i);
                break;
            }
            m[nums[i]] = i;
        }
        return result;
    }
};
