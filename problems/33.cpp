#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int bsearch(vector<int>& nums, int left, int right, int target) {
        int l, r, m;
        if (left > right) return -1;
        if (left == right) return nums[left] == target ? left : -1;
        if (nums[left] < nums[right]) {
            l = left;
            r = right;
            while (l <= r) {
                m = (l + r) / 2;
                if (nums[m] == target) {
                    return m;
                } else if (nums[m] > target) {
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            }
            return -1;
        }
        m = (left + right) / 2;
        if (nums[left] < nums[m]) {
            if (target >= nums[left] && target <= nums[m]) {
                return bsearch(nums, left, m, target);
            }
        }
        if (nums[m] < nums[right]) {
            if (target >= nums[m] && target <= nums[right]) {
                return bsearch(nums, m, right, target);
            }
        }
        int x = bsearch(nums, left, m, target);
        if (x != -1) return x;
        return bsearch(nums, m + 1, right, target);
    }

    int search(vector<int>& nums, int target) {
        return bsearch(nums, 0, nums.size() - 1, target);
    }
};

int main() {
    Solution s;
    int arr[] = {1, 2, 1, 1, 1, 1};
    vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));
    cout << s.search(v, 2) << endl;
    return 0;
}