class Solution {
public:
    void DFS(vector<vector<char>>& board, int x, int y, char c) {
        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] != 'O') return;
            
        board[x][y] = c;
        
        DFS(board, x + 1, y, c);
        DFS(board, x - 1, y, c);
        DFS(board, x, y + 1, c);
        DFS(board, x, y - 1, c);
    }
    
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        
        // Change the 'O's connected to border to '!'
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O') DFS(board, i, 0, '!');
            if (board[i][m-1] == 'O') DFS(board, i, m-1, '!');
        }
        
        for (int i = 0; i < m; i++) {
            if (board[0][i] == 'O') DFS(board, 0, i, '!');
            if (board[n-1][i] == 'O') DFS(board, n-1, i, '!');
        }
        
        // Change all remaining 'O's to 'x' and '!' back to 'O'
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i && j && i < n - 1 && j < m - 1 && board[i][j] == 'O') board[i][j] = 'X';
                if (board[i][j] == '!') board[i][j] = 'O';
            }
        }
    }
};
