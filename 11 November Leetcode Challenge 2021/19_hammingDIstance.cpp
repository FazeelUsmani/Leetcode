class Solution {
public:
    int hammingDistance(int x, int y) {
        
        int cnt = 0;        
        for (int i = 0; i < 32; ++i) {                        
            int a = ((x>>i)&1);
            int b = ((y>>i)&1);
            
            if (a == b){
                continue;
            }
            else if (((a == 1) && (b == 0)) || ((b == 1) && (a == 0))){
                cnt++;
            }             
        }
        
        return cnt;        
    }
};
