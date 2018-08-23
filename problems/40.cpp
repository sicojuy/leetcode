#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        dfs(result, candidates, path, 0, 0, target);
        return result;
    }

    void dfs(vector<vector<int>>& result, vector<int>& candidates, vector<int>& path, int pos, int sum, int target) {
        int i, j;
        j = path.size();
        path.push_back(0);
        for (i = pos; i < candidates.size(); i++) {
            if (i > pos && candidates[i] == candidates[i-1]) continue;
            if (sum + candidates[i] == target) {
                path[j] = candidates[i]; 
                result.push_back(path);
            } else if (sum + candidates[i] < target) {
                path[j] = candidates[i];
                dfs(result, candidates, path, i+1, sum+candidates[i], target);
                path.resize(j+1);
            } else {
                break;
            }
        }
    }
};