class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
                
        int dp[366] = {0}, j = 0;;
        for (int i = 1; i < 366; ++i){
            dp[i] = costs[0] + dp[i-1];            
            if (i-7 >= 0)
                dp[i] = min(dp[i], dp[i-7] + costs[1]);
            if (i-30 >= 0)
                dp[i] = min(dp[i], dp[i-30] + costs[2]);
            
            if (j < days.size() && days[j] == i)
                j++;
            else
                dp[i] = min(dp[i], dp[i-1]);            
        }
        
        return dp[365];        
    }
};
