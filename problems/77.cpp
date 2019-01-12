#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> v(k);
        int i, j;
        for (i = 0; i < k; i++) v[i] = i+1;
        result.push_back(v);
        while (true) {
            for (i = 0; i + 1 < k; i++) {
                if (v[i] + 1 < v[i+1]) break;
            }
            if (i + 1 == k && v[i] == n) break;
            v[i]++;
            for (j = 0; j < i; j++) {
                v[j] = j+1;
            }
            result.push_back(v);
        }
        return result;
    }
};