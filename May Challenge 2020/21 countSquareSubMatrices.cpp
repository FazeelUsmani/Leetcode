class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        
        int row = matrix.size();
        int col = matrix[0].size();
        int ans = 0;
        
        vector<vector<int>> pre (row, vector<int> (col, 0));
        
        for (int i = 0; i < col; i++)
            ans += matrix[row-1][i];
        
        for (int i = 0; i < row; i++)
            ans += matrix[i][col-1];
        ans -= matrix[row-1][col-1];
        
        for (int i = row-2; i >= 0; i--){
            for (int j = col-2; j >= 0; j--){
                matrix[i][j] = matrix[i][j]==1 ? 1+min({matrix[i+1][j+1],matrix[i] [j+1],matrix[i+1][j]}):0;
                ans += matrix[i][j];
            }
        }
        
        return ans;        
    }
};
