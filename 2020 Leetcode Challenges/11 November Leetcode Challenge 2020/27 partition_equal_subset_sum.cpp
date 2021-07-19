class Solution {
public:
    
    bool canPartition(vector<int>& nums) {
        
        int total = 0;
        
        for (int x : nums) {
            total += x;
        }
        
        if (total & 1)
            return false;
        
        int sum = total/2;
        int n = nums.size();
        
        bool dp[n + 1][sum + 1];
        memset(dp, 0, (n + 1) * (sum + 1) * sizeof(bool));
        dp[0][0] = true;       
        
        for (int i = 1; i <= n; ++i) {
            int curr = nums[i-1];
            for (int j = 0; j <= sum; ++j) {
                if (j < curr)
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-curr];                
            }
        }
        
        return dp[n][sum];
    }
};
