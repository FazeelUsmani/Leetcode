class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        // edge case - zero AND anything will always stay zero
        if ((m == 0) || (n == 0)) return 0;
        
        // if there is a different amount of digits in binary - always will be zero
        if ((int)log2(m) != (int)log2(n)) return 0;
        
        // None of the above - not too many numbers left to calculate one by one...
        int res = m;
        for (long i = m; i <= n; i++)
            res &= i;
                
        return res;
    }
};
