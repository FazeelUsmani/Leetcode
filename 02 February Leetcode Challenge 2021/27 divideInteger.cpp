class Solution {
public:
    int divide(int dividend, int divisor) {
        
        int sign = (dividend < 0) ^ (divisor < 0);
        
        long dvnd = abs(dividend);
        long dvsr = abs(divisor);
        
        long res = exp(log(dvnd) - log(dvsr));
        
        res *= (sign ? -1 : 1);
        
        if(res > INT_MAX)
            return INT_MAX;
        
        if(res < INT_MIN)
            return INT_MIN;
        
        return res;
        
    }
};
