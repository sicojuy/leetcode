#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int ans = 0;
        int i, j;
        sort(people.begin(), people.end());
        i = 0;
        j = people.size() - 1;
        while (i <= j) {
            if (people[i] + people[j] <= limit) {
                i++;
                j--;
            } else {
                j--;
            }
            ans++;
        }
        return ans;
    }
};