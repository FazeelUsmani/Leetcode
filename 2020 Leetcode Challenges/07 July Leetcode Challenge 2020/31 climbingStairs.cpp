class Solution {
public:
    int climbStairs(int n) {
        
        if (n <= 0)
            return 0;
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        
        vector<int> jump (n+1, 0);
        jump[1] = 1;
        jump[2] = 2;
        for (int i = 3; i <= n; ++i){
            jump[i] = jump[i-1] + jump[i-2];
        }
        
        return jump[n];
    }
};
