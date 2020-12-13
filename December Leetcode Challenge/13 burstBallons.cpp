public:
    int maxCoins(vector<int>& nums) {
        vector<int> num{1};
        num.insert(num.end(), nums.begin(), nums.end());
        num.push_back(1);
        int sz = num.size();
        vector<vector<int>> dp(sz, vector<int>(sz));
        for(int i=2;i<sz;++i){
            for(int j=i-1;j>=1;--j){
                for(int k=j-1;k>=0;--k){
                    dp[k][i] = max(dp[k][i], num[k]*num[j]*num[i]+dp[k][j]+dp[j][i]);
                }
            }
        }
        return dp[0][sz-1];
    }
};
