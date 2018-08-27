#include <vector>
using namespace std;

class Solution {
public:
    int _trap(vector<int>& height, int l, int r) {
        int i, j, k;
        int ans, h;
        if (l+1 >= r) return 0;
        if (height[l] > height[r]) {
            i = l; 
            j = r;
        } else {
            i = r;
            j = l;
        }
        for (k = l+1; k < r; k++) {
            if (height[k] > height[i]) {
                j = i;
                i = k;
            } else if (height[k] > height[j]) {
                j = k;
            }
        }
        h = height[j];
        if (i > j) swap(i, j);
        ans = 0;
        for (k = i + 1; k < j; k++) {
            ans += h - height[k];
        }
        return _trap(height, l, i) + _trap(height, j, r) + ans;
    }

    int trap(vector<int>& height) {
        return _trap(height, 0, height.size()-1);
    }
};