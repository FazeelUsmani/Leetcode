class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& A) {
        
        int row = A.size();
        if (row == 0)   return 0;
        int col = A[0].size();        
        
        auto check = [&](int x, int y) {
            return (0<=x && x<row && 0<=y && y<col);
        };               
        
        int visited[row][col];
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                visited[i][j] = 0;
            }
        }
        
        vector<pair<int, int> > directions { {-1,0}, {1,0}, {0,-1}, {0, 1} };
        int cnt = 0;
        int ans = 0;
        
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                cnt = 0;
                if (A[i][j] == 1 && !visited[i][j]) {
                    queue<pair<int, int> > q;
                    q.push(make_pair(i, j));
                    visited[i][j] = 1;
                    cnt = 1;
                    
                    while (!q.empty()) {
                        pair<int, int> curr = q.front();
                        q.pop();
                        
                        for (pair<int, int> dir: directions) {
                            int newX = curr.first + dir.first;
                            int newY = curr.second + dir.second;
                            
                            if (check(newX, newY) && !visited[newX][newY] && A[newX][newY] == 1) {
                                q.push(make_pair(newX, newY));
                                cnt++;
                                visited[newX][newY] = 1;
                            }
                            
                        }
                    }
                    ans = max(ans, cnt);                    
                }                
            }
        }
        return ans;                  
     }
};
