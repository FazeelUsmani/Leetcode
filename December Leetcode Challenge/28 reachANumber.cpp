class Solution {
public:
    int reachNumber(int target) {
        
        target = abs(target);
        int k = 0;
        
        while (target > 0) {
            k += 1;
            target -= k;
        }
        
        if ((target%2) == 0) 
            return k;
        
        return (k+1+(k%2));        
    }
};
