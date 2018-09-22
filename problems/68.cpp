#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        string line;
        int count, width;
        int i, j, k;
        count = 1;
        width = words[0].length();
        line = words[0];
        for (i = 1; i < words.size(); i++) {
            if (width + words[i].length() + 1 > maxWidth) {
                line = words[i - count];
                for (j = i - count + 1, k = 0; j < i; j++, k++) {
                    if (k < (maxWidth - width) % (count - 1)) {
                        line += string((maxWidth - width) / (count - 1) + 2, ' ');
                    } else {
                        line += string((maxWidth - width) / (count - 1) + 1, ' ');
                    }
                    line += words[j];
                }
                if (count == 1) line += string(maxWidth - width, ' ');
                ans.push_back(line);
                count = 1;
                width = words[i].length();
                line = words[i];
            } else {
                width += words[i].length() + 1;
                count += 1;
            }
        }
        line = words[i - count];
        for (j = i - count + 1; j < i; j++) {
            line += " ";
            line += words[j];
        }
        line += string(maxWidth - width, ' ');
        ans.push_back(line);
        return ans;
    }
};

int main() {
    vector<string> words;
    int maxWidth = 5;
    words.push_back("ac");
    words.push_back("de");
    words.push_back("deddd");
    words.push_back("d");
    Solution s;
    auto ans = s.fullJustify(words, maxWidth);
    for (auto it = ans.begin(); it != ans.end(); it++) {
        cout << *it << endl;
    }
    return 0;
}