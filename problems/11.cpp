#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i, j, k;
        int curArea, maxArea;
        i = 0;
        j = height.size() - 1;
        maxArea = 0;
        while (i < j) {
            curArea = (j - i) * min(height[i], height[j]);
            if (curArea > maxArea) {
                maxArea = curArea;
            }
            if (height[i] < height[j]) {
                i = i + 1;
            } else {
                j = j - 1;
            }
        }
        return maxArea;
    }
};