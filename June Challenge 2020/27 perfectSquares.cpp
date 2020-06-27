class Solution {
public:
    int numSquares(int n) {
        
        int minSq[n+1];
        minSq[0] = 0;
        
        for (int i = 1; i <= n; ++i){
            minSq[i] = INT_MAX;
            for (int j = 1; j * j <= i; ++j){
                minSq[i] = min (minSq[i], minSq[i-j*j] + 1);
            }
        }
        
        return minSq[n];        
    }
};
