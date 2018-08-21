#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int i, j, l, r;
        int sum;
        vector<vector<int>> result;
        vector<int> item(4);
        sort(nums.begin(), nums.end());
        for (i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            if (target >= 0 && nums[i] > target) continue;
            for (j = i + 1; j < nums.size(); j++) {
                if (j > i + 1 && nums[j] == nums[j-1]) continue;
                if (target >= 0 && nums[i] + nums[j] > target) continue;
                l = j + 1;
                r = nums.size() - 1;
                while (l < r) {
                    sum = nums[i] + nums[j] + nums[l] + nums[r];
                    if (sum == target) {
                        item[0] = nums[i];
                        item[1] = nums[j];
                        item[2] = nums[l++];
                        item[3] = nums[r--];
                        result.push_back(item);
                        while (l < r && nums[l] == nums[l-1]) l++;
                        while (l < r && nums[r] == nums[r+1]) r--;
                    } else if (sum > target) {
                        r--;
                        while (l < r && nums[r] == nums[r+1]) r--;
                    } else {
                        l++;
                        while (l < r && nums[l] == nums[l-1]) l++;
                    }
                }
            }
        }
        return result;
    }
};

int main() {
    int arr[] = {1,-2,-5,-4,-3,3,3,5};
    int target = -11;
    vector<int> nums(arr, arr + sizeof(arr) / sizeof(arr[0])); 
    Solution s;
    vector<vector<int>> res;
    res = s.fourSum(nums, target);
    cout << "[";
    for (vector<vector<int>>::iterator it = res.begin(); it != res.end(); it++) {
        cout << "[";
        for (vector<int>::iterator it2 = it->begin(); it2 != it->end(); it2++) {
            cout << *it2 << ",";
        }
        cout << "]";
    }
    cout << "]" << endl;
    return 0;
}