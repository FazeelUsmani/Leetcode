#include <math.h>

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();        
        if (n == 0) return 0;
        vector<int> minLeft(n, 0), maxRight(n, 0);
        
        minLeft[0] = prices[0];
        for (int i = 1; i < n; ++i) {
            minLeft[i] = min(minLeft[i-1], prices[i]);
        }
        
        maxRight[n-1] = prices[n-1];
        for (int i = n-2; i >= 0; --i){
            maxRight[i] = max(maxRight[i+1], prices[i]);
        }
        
        int ans = 0;
        for (int i = 0; i < n; ++i){
            int diff = abs(minLeft[i] - maxRight[i]);
            ans = max(ans, diff);
        }
        
        return ans;
    }
};
