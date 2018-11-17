#include <queue>
using namespace std;

class RecentCounter {
    queue<int> q;
public:
    RecentCounter() {
    }
    
    int ping(int t) {
        q.push(t);        
        while (q.back() - q.front() > 3000) {
            q.pop();
        }
        return q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */