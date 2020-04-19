class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        const int INF = 1e9 + 5;   // can also use INT_MAX
        int H = grid.size();
        int W = grid[0].size();
        vector<vector<int>> dp(H, vector<int>(W));
        for (int row = 0; row < H; ++row){
            for (int col = 0; col < W; ++col){
                if (row == 0 && col == 0){
                    dp[row][col] = grid[row][col];
                }
                else{
                dp[row][col] = grid[row][col] + min((row == 0?INF:dp[row-1][col]), (col==0?INF:dp[row][col-1]));
                }
            }
        }
        return dp[H-1][W-1];
        
    }
};
