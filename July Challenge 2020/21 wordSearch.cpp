class Solution {
public:
    
    vector<pair<int, int>> directions { {-1,0}, {0, -1}, {1, 0}, {0, 1} };
    
    bool isSafe(int N, int M, int i, int j){
        return (i<N) && (i>=0) && (j>=0) && (j<M);
    }
    
    bool backtrack(vector<vector<char>> &board, string &word, int pos, int i, int j){
        if (word[pos] != board[i][j])
            return false;
        
        if (pos == word.length()-1)
            return true;
        
        // Marking as # such that it doesn't matches in future occurences during backtracking
        board[i][j] = '#';
        
        
        for (pair<int, int> dir: directions)
            if (isSafe(board.size(), board[i].size(), i+dir.first, j+dir.second))
                if (backtrack(board, word, pos+1, i+dir.first, j+dir.second))
                    return true;
        
        // Un-marking: convertin '#' to original character
        board[i][j] = word[pos];
        
        return false;        
    }   
    
    
    bool exist(vector<vector<char>>& board, string word) {
        
        for (int i = 0; i < board.size(); ++i)
            for (int j = 0; j < board[i].size(); ++j)               
                if (backtrack(board, word, 0, i, j))
                    return true;
                
        return false;              
    }
};
