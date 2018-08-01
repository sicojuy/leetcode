#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        string item;
        string letters[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        int len = digits.length();
        if (len == 0) {
            return result;
        }
        int lengths[len];
        int indexs[len];
        int i, j;
        for (i = 0; i < len; i++) {
            j = digits[i] - '0';
            lengths[i] = letters[j].length();
            indexs[i] = 0;
        }
        while (true) {
            item.clear();
            for (i = 0; i < len; i++) {
                j = digits[i] - '0';
                item.push_back(letters[j][indexs[i]]);
            }
            result.push_back(item);

            indexs[len-1]++;
            for (i = len - 1; i > 0; i--) {
                if (indexs[i] < lengths[i]) {
                    break;
                } 
                indexs[i] = 0;
                indexs[i-1]++;
            }
            if (indexs[0] == lengths[0]) {
                break;
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<string> result;
    result = s.letterCombinations("234");
    for (auto it = result.begin(); it != result.end(); it++) {
        cout << *it << endl;
    }
    return 0;
}