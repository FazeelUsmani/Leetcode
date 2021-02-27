class Solution {
public:
    
    bool validPosition(int &x, int &y, const int &N) {
        return x >= 0 && x < N &&
            y >= 0 && y < N;
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1)
            return -1;
        
        const int N = grid.size();
        // possible 8 directional steps
        vector<vector<int>> moves = {{-1,0}, {-1,-1},
                                     {0,-1}, {1,-1},
                                    {1,0}, {1,1},
                                    {0,1}, {-1,1}};
        // keeps track of visited positions
        vector<vector<bool>> visited(N, vector<bool>(N, false));
        
        queue<pair<int, int>> q;
        // starting point: top left
        q.emplace(make_pair(0, 0));
        // mark start as visited
        visited[0][0] = true;
        
        int level = 0, n_level = q.size();
        // BFS to find the level in which the last cell can be reached
        while(!q.empty())  {
            auto curr = q.front();
            q.pop();
            --n_level;
            
            if(curr.first == N-1 && curr.second == N-1)
                return level + 1;
            // add the unvisited neighbours
            for(auto move: moves) {
                int x = move[0] + curr.first;
                int y = move[1] + curr.second;
                // if the neighbour is unvisited and at valid position
                if(validPosition(x, y, N) && !visited[x][y]
                  && grid[x][y] == 0) {
                    visited[x][y] = true;
                    q.emplace(make_pair(x, y));
                }
            }
            // end of level
            if(!n_level) {
                ++level;
                n_level = q.size();
            }
        }
        
        return -1;    
        
    }
};
