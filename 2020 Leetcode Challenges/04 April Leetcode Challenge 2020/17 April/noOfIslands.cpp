class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        // This can be solved using BFS, DFS and Find & Union / Disjoint Set Union [a bit slower]
        // Elegant solution
        // This solution uses Queue using DFS
        
        if (grid.empty() || grid[0].empty())
            return 0;
        
        int H = grid.size();
        int W = grid[0].size();
        int answer = 0;
        
        // To check whether the control is inside the matrix {Boundary condition}
        auto inside = [&](int row, int col){
            return 0 <= row && row < H && 0 <= col && col < W;
        };
        
        // Maintaining a directors vector and traversing in 4 directions from a cell
        vector<pair<int, int>> directions{{1,0}, {0,1}, {-1,0}, {0, -1}};
        
        // visited[H][W]
        vector<vector<bool>> visited(H, vector<bool>(W));
        
        for (int row = 0; row < H; row++){
            for (int col = 0; col < W; col++){
                if (!visited[row][col] && grid[row][col] == '1'){
                    answer++;
                    // Start of DFS
                    queue<pair<int, int>> q;
                    q.push({row, col});
                    visited[row][col] = true;
                    while (!q.empty()){
                        pair<int, int> p = q.front();
                        q.pop();
                        
                        for (pair<int, int> dir : directions){
                            int new_row = p.first + dir.first;
                            int new_col = p.second + dir.second;
                            
                            // p.first, p.second 
                            // inside() to check it's not on boundary
                            if (inside(new_row,new_col) && !visited[new_row][new_col] && grid[new_row][new_col] == '1'){
                                q.push({new_row, new_col});
                                visited[new_row][new_col] = true;
                            }                            
                        }                                                
                    }                    
                }
            }
        }
        
        return answer;
    }
};
