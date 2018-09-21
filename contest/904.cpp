#include <vector>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int result = 0;
        int s1, s2;
        int c1, c2;
        int i, j;
        s1 = tree[0];
        s2 = -1;
        c1 = 1;
        c2 = 0;
        for (i = 1, j = 0; i < tree.size(); i++) {
            if (tree[i] == s1) {
                c1++;
            } else if (tree[i] == s2) {
                c2++;
            } else if (s2 == -1) {
                s2 = tree[i];
                c2++;
            } else {
                if (c1 + c2 > result) result = c1 + c2;
                s1 = tree[i-1];
                c1 = i - j;
                s2 = tree[i];
                c2 = 1;
            }
            if (tree[i] != tree[j]) j = i;
        }
        if (c1 + c2 > result) result = c1 + c2;
        return result;
    }
};