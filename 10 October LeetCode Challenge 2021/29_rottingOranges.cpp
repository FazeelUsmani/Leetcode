class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        if (grid.empty() || grid[0].empty())
            return 0;
        
        int H = grid.size();
        int W = grid[0].size();
        
        auto inside = [&](int row, int col){
            return 0<=row && row<H && 0<=col && col<W;
        };
        
        queue<pair<int, int> > q;
                    
        for (int i = 0; i < H; ++i){
            for (int j = 0; j < W; ++j){
                if (grid[i][j] == 2){
                    q.push({i, j});
                }
            }
        }
                
        vector<pair<int, int> > directions { {-1,0}, {0,-1}, {1,0}, {0,1} };
        int minutes = 0;
        
        while (!q.empty()){
            
            int sz = q.size();
            bool flag = false;
            for (int k=0; k<sz; ++k){
                pair<int, int> orange = q.front();
                q.pop();
                int i = orange.first, j = orange.second;
                  
                for (pair<int, int> dir: directions){
                    int newRow = i + dir.first;
                    int newCol = j + dir.second;
                    if (inside(newRow,newCol) && grid[newRow][newCol] == 1){                  
                        flag = true;
                        q.push({newRow, newCol});                        
                        grid[newRow][newCol] = 2;
                    }
                }                
            }            
            if (flag)
                minutes++;            
        }
        
        for(auto rows : grid)
            for(auto val : rows)
                if(val == 1)
                    return -1;        
        
        return minutes;
    }
};
