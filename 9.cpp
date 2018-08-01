class Solution {
public:
    bool isPalindrome(int x) {
        int t = x;
        int y = 0;       
        if (x < 0) return false;
        while (t) {
            y = y * 10 + t % 10;
            t = t / 10;
        } 
        return y == x;
    }
};