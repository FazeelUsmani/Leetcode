class Solution {
public:
    int arrangeCoins(int n) {
        
        int k = 1, completeSteps = 0;
        
        while (n > 0){
            n -= k++;
            if (n >= 0)
                ++completeSteps;            
        }
        
        return completeSteps;        
    }
};
