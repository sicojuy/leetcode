#include <string>
#include <iostream>
#include <algorithm>
using namespace std;


class Solution {
public:
    string orderlyQueue(string S, int K) {
        int i, j;
        if (S.size() < 2) return S;
        if (K > 1) {
            sort(S.begin(), S.end());
            return S;
        }
        int p = 0;
        for (i = 1; i < S.size(); i++) {
            for (j = 0; i + j < S.size(); j++) {
                if (S[i+j] < S[p+j]) {
                    p = i;
                    break;
                } else if (S[i+j] > S[p+j]) {
                    break;
                }
            }
            if (i + j == S.size()) {
                p = i;
            }
        }

        return S.substr(p) + S.substr(0, p);
    }
};

int main() {
    Solution s;
    string S = "ndcxdxmlikjoivggmyasaktllgmfhqpyznchnryeawutmrkekuuyxrnseysplqqxoflgxvofbdlrfrwtlqzxireojllrvmdttykmoxsafwpwkfazdqmjnczmaktittgzawndgphvfjnivgceqobzmisalrztxdlahjijuevoioemawiizpkubonwpmnujoszszkptjgzjzwfvzhrucvisyaphcsznjlknkczzeglsavqhwriozbswsdpukpgivmldjngvjgivxyatndghkmybswjgfhdogagvkwygowpegzhwutsuwbenfnmdcavczztlhkiksxegfbwnbllutdqnadrjznrdmtvfkmlmhvxjqjpsnrtvefnnvnxunvmillqbszlbfcguawyeezjvazapyvivkmjjpustanjfxfeerpnpywxbxaqynkixyqsidzrhzpixcuecgspkeytrvucuvtmrctguqnnbbauddkzxivckpzbkxap";
    int k = 1;
    cout << s.orderlyQueue(S, k) << endl;
    return 0;
}