class Solution {
public:
    int brokenCalc(int X, int Y) {
        
        int ans = 0;
        while (Y > X){
            ans += 1;
            if (Y%2) Y += 1;
            else Y /= 2;
        }
            
        return ans + X-Y;        
    }
};
