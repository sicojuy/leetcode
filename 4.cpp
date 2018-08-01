#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

const int INF = 0x7FFFFFFF;
const int NINF = 0x80000000;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        int l1, l2, r1, r2, p1, p2, n1, n2;
        int vl1, vl2, vr1, vr2;

        n1 = nums1.size();
        n2 = nums2.size();
        if (n1 == 0 && n2 == 0) {
            return 0.0;
        }

        l1 = l2 = 0;
        r1 = n1;
        r2 = n2;
        while (true) {
            p1 = (l1 + r1) / 2;
            p2 = (l2 + r2) / 2;
            vl1 = p1 > 0 ? nums1[p1 - 1] : NINF;
            vl2 = p2 > 0 ? nums2[p2 - 1] : NINF;
            vr1 = p1 < n1 ? nums1[p1] : INF;
            vr2 = p2 < n2 ? nums2[p2] : INF;
            if (p1 + p2 < (n1 + n2) / 2) {
                if (l2 == n2 || vr1 < vr2) {
                    l1 = p1 + 1;
                } else {
                    l2 = p2 + 1;
                }
            } else if (p1 + p2 > (n1 + n2) / 2) {
                if (r2 == 0 || vl1 > vl2) {
                    r1 = p1 - 1;
                } else {
                    r2 = p2 - 1;
                }
            } else {
                if (vl2 > vr1) {
                    l1 = p1 < n1 ? p1 + 1 : p1;
                    r2 = p2 > 0 ? p2 - 1 : p2;
                } else if (vl1 > vr2) {
                    l2 = p2 < n2 ? p2 + 1 : p2;
                    r1 = p1 > 0 ? p1 - 1 : p1;
                } else {
                    break;
                }
            }
        }

        if ((n1 + n2) & 1) {
            return double(min(vr1, vr2));
        } else {
            return double(min(vr1, vr2) + max(vl1, vl2)) / 2.0;
        }
    }
};