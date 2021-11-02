static int X[4] = {-1, 0, 1, 0};
static int Y[4] = {0, -1, 0, 1};

class Solution {
public:
    
    int countPaths(vector<vector<int>>& grid, int x, int y, int empty, const int& m, const int& n) {
        
		/*
		for(int i=0; i<m; i++) {
			for(int j=0; j<n; j++) {
				cout << grid[i][j] << " ";
			}
			cout << endl;
		}
		cout << x << " : " << y << " -> " << empty << endl << endl;
		*/
		
		// If we reach end cell and 
		// All empty cells are visited, then return 1
		// Else return 0
        if(grid[x][y] == 2) {
            return (empty == 0);
        }
                
        int count = 0;   // Count of possible paths from current cell {x,y}
        grid[x][y] = -1;  // Visit
        
		// Check for all valid directions
        for(int k=0; k<4; k++) {
			// Possible adjacent coordinates
            int i = x + X[k];
            int j = y + Y[k];
			
			// Valid Moves
            if(i>=0 && j>=0 && i<m && j<n && grid[i][j] != -1) {
                count += countPaths(grid, i, j, empty-1, m, n);  // Add count of possible paths
            }
        }
        
		// Backtrack 
        grid[x][y] = 0;  // Unvisit
        
        return count;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        
        int m = grid.size(), n = grid[0].size(), empty = 1;
        
        pair<int, int> start;
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1) start = {i, j};
                else if(grid[i][j] == 0) empty++;  // Count of empty cells
            }
        }
        
		// Explore grid from start cell
        return countPaths(grid, start.first, start.second, empty, m, n);
    }
};
