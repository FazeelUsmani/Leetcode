class Solution {
public:
    int numTrees(int n) {
        
        int numBST[n+1];
        fill_n(numBST, n+1, 0);
        
        numBST[0] = 1;
        numBST[1] = 1;
        
        for (int i = 2; i <= n; ++i){
            for (int j = 1; j <= i; ++j){
                
                numBST[i] = numBST[i] + (numBST[i-j] * numBST[j-1]);
            }
        }
        
        return numBST[n];
    }
};
