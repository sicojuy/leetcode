#include <vector>
using namespace std;

class Solution {
public:
    int gcd(int a, int b) {
        int t;
        while (b != 0) {
            t = b;
            b = a % b;
            a = t;
        }
        return a;
    }

    bool hasGroupsSizeX(vector<int>& deck) {
        int m[10000] = {0};
        int x = 0;
        for (int i = 0; i < deck.size(); i++) {
            m[deck[i]]++;
        }
        for (int i = 0; i < 10000; i++) {
            if (m[i] == 0) continue;
            if (x == 0) {
                x = m[i];
                continue;
            }
            x = gcd(m[i], x); 
            if (x < 2) return false;
        }
        return x > 1;
    }
};