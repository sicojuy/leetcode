#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> m;
        unordered_map<string, vector<string>>::iterator v;
        vector<string> group;
        string s;
        for (auto it = strs.begin(); it != strs.end(); it++) {
            s = *it;
            sort(s.begin(), s.end());
            v = m.find(s);
            if (v == m.end()) {
                group.clear();
                group.push_back(*it);
                m.insert(make_pair(s, group));
            } else {
                v->second.push_back(*it);
            }
        }
        for (auto it = m.begin(); it != m.end(); it++) {
            result.push_back(it->second);
        }
        return result;
    }
};