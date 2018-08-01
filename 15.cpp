#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;       
        vector<int> item(3);
        int i, l, r;
        int sum;
        sort(nums.begin(), nums.end());
        for (i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            if (nums[i] > 0) break;
            l = i + 1;
            r = nums.size() - 1;
            while (l < r) {
                sum = nums[i] + nums[l] + nums[r];
                if (sum == 0) {
                    item[0] = nums[i];
                    item[1] = nums[l++];
                    item[2] = nums[r--];
                    result.push_back(item);
                    while (l < r && nums[l] == nums[l-1]) l++;
                    while (l < r && nums[r] == nums[r+1]) r--;
                } else if (sum > 0) {
                    r--;
                    while (l < r && nums[r] == nums[r+1]) r--;
                } else {
                    l++;
                    while (l < r && nums[l] == nums[l-1]) l++;
                }
            }
        }
        return result;
    }
};

int main() {
    int arr[] = {1, 0, 0, 0, -1};
    vector<int> nums(arr, arr + sizeof(arr) / sizeof(arr[0])); 
    Solution s;
    vector<vector<int>> res;
    res = s.threeSum(nums);
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
