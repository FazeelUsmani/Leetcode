class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        int cnt = 0;
        while (n > 0){
            n = n & (n-1);
            cnt++;            
        }
        
        return (cnt == 1) ? true : false;
        
    }
};
