class Solution {
public:
    bool isPowerOfThree(int n) {
        
        if (n <= 0) return false;
        int d = int(log2(n)/log2(3));
        return pow(3, d) == n;
        
    }
};
