
class Solution {
public:
    int binaryGap(int N) {
        int maxLen, curLen;
        maxLen = 0;
        curLen = -1;
        while (N) {
            if (N & 1) {
                if (curLen == -1) {
                    curLen = 1;
                } else {
                    if (curLen > maxLen) {
                        maxLen = curLen;
                    }
                    curLen = 1;
                }
            } else {
                if (curLen != -1) {
                    curLen++; 
                }
            }
            N = N >> 1;
        }        
        return maxLen;
    }
};