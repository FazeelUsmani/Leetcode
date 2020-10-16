class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        
        int row = matrix.size();
        if (row == 0)
            return false;
        int col = matrix[0].size();
        bool flag = false;
        int i = 0, j = col-1;
        
        while ((i < row) && (j >= 0)) {
            if (matrix[i][j] > target)
                j = j-1;
            else if (matrix[i][j] < target)
                i = i+1;
            else if (matrix[i][j] == target){
                flag = true;
                break;
            }
        }
        
        return flag;    
    }
};
