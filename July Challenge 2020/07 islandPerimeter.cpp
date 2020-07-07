class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        
        int H = grid.size(), W = grid[0].size(); 
        
        vector<pair<int, int> > directions { {-1,0}, {0, -1}, {1, 0}, {0, 1} };
        
        vector<vector<int> > visited (H, vector<int> (W, 0));
        
        auto inside = [&](int x, int y){
            
            return 0 <= x && x < H && 0 <= y && y < W;
        };
        
//         for (int i = 0; i < H; ++i){
//             for (int j = 0; j < W; ++j){                             
//                 if (grid[i][j] == 0){
//                     visited[i][j] = 1;
//                 }
//             }
//         }
        
        queue<pair<int, int> > q;
        
        for (int i = 0; i < H; ++i){
            for (int j = 0; j < W; ++j){                             
                if (grid[i][j] == 1){
                    q.push({i, j});
                    visited[i][j] = 1;
                    break;
                }                                         
            }
        }
        
        int perimeter = 0;
        
        while (!q.empty()){
            
            pair<int, int> front = q.front();
            q.pop();          

            for (pair<int, int> dir : directions){
        
                int new_row = front.first + dir.first;
                int new_col = front.second + dir.second;
                
                if (!inside(new_row, new_col)){
                    ++perimeter;
                }
                else if (inside(new_row, new_col) && !visited[new_row][new_col]){
                    if (grid[new_row][new_col] == 1){
                        visited[new_row][new_col] = 1;
                        q.push({new_row, new_col});                        
                    }
                    else if (grid[new_row][new_col] == 0 && !visited[new_row][new_col]){
                        ++perimeter;
                    }
                }                
            }                              
        }
        
        return perimeter;      
    }
};
