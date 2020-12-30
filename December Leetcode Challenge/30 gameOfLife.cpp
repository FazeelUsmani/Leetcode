class Solution {
public:
    int row, col;    
    vector<pair<int, int> > dir { {-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0,1}, {1,-1}, {1,0}, {1,1} };
    
    bool check (int a, int b, vector<vector<int>> &A) {
        
        int cnt = 0;
        int curr = A[a][b];
        
        for (pair<int, int> x: dir) {
            int i = a+x.first, j = b+x.second;
            if ((i >= 0 && i < A.size()) && (j >= 0 && j < A[0].size()) ){
                if (A[i][j] == 1) {
                    cnt++;
                }                
            }            
        }
        
        if (curr == 0){
            if (cnt == 3) {
                return true;
            }
            return false;
        }
        else if ((cnt == 2) || (cnt == 3))
           return true;    
        
        return false;
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        row = board.size();
        col = board[0].size();
        if (row == 0)
            return;
        
        vector<vector<int> > A (row, vector<int> (col, 0));
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                A[i][j] = board[i][j];         
            }
        }
                        
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {                
                if (check(i, j, A)) 
                    board[i][j] = 1;                
                else 
                    board[i][j] = 0;
            }
        }                     
    }
};
