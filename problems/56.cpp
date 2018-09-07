#include <vector>
#include <algorithm>
using namespace std;

/**
 * Definition for an interval.
 */
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool cmp(Interval &x, Interval &y) {
    return x.start < y.start;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> result;
        if (intervals.empty()) return result;
        sort(intervals.begin(), intervals.end(), cmp);
        Interval cur = intervals[0];
        for (int i = 1; i < intervals.size(); i++) {
            if (cur.end < intervals[i].start) {
                result.push_back(cur);
                cur = intervals[i];
            } else {
                cur.start = min(cur.start, intervals[i].start);
                cur.end = max(cur.end, intervals[i].end);
            }
        }
        result.push_back(cur);
        return result;
    }
};