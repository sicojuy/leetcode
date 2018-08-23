#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> _combinationSum(vector<int>& candidates, int pos, int target) {
        vector<vector<int>> result, tmp;
        vector<int> v(1);
        for (int i = pos; i < candidates.size(); i++) {
            if (candidates[i] < target) {
                tmp = _combinationSum(candidates, i, target - candidates[i]);
                for (auto it = tmp.begin(); it != tmp.end(); it++) {
                    (*it).push_back(candidates[i]);
                    result.push_back(*it);
                }
            } else if (candidates[i] == target) {
                v[0] = candidates[i];
                result.push_back(v);
            } else {
                break;
            }
        }
        return result;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        return _combinationSum(candidates, 0, target);
    }
};