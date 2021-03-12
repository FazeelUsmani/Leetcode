class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
                
        vector<double> dp(amount+1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i<= amount; ++i) {
            for (int x: coins) {
                if (i >= x) {
                    dp[i] = min(dp[i], 1+dp[i-x]);
                }
            }
        }
        return (dp.back()==INT_MAX) ? -1 : dp.back();
    }
};
