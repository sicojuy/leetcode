#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<string> recursiveGenerate(int n) {
        vector<string> result;
        if (n == 1) {
            result.push_back("()");
            return result;
        }
        auto middle = generateParenthesis(n-1);
        for (auto it = middle.begin(); it != middle.end(); it++) {
            result.push_back("(" + *it + ")");
        }
        for (int i = 1; i < n; i++) {
            auto left = generateParenthesis(i);
            auto right = generateParenthesis(n-i);
            for (auto it1 = left.begin(); it1 != left.end(); it1++) {
                for (auto it2 = right.begin(); it2 != right.end(); it2++) {
                    result.push_back(*it1 + *it2);
                }
            }
        }
        return result;
    }

    vector<string> generateParenthesis(int n) {
        auto result = recursiveGenerate(n);
        unordered_set<string> s;
        for (auto it = result.begin(); it != result.end(); it++) {
            s.insert(*it);
        }
        result.clear();
        for (auto it = s.begin(); it != s.end(); it++) {
            result.push_back(*it);
        }
        return result;
    }
};

int main() {
    Solution s;
    auto result = s.generateParenthesis(3);
    for (auto it = result.begin(); it != result.end(); it++) {
        cout << *it << endl;
    }
    return 0;
}