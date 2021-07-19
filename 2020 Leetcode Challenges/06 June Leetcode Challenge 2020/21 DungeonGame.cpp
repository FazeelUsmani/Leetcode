class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        
        int m = dungeon.size(), n = dungeon[0].size();
        
        if (m == 0) return 0;
        
        for (int i = m-1; i >= 0; --i){
            for (int j = n-1; j >= 0; --j){
                if (i == m-1 && j == n-1)
                    dungeon[i][j] = max( 1, 1-dungeon[i][j]);
                else if (i == m-1)
                    dungeon[i][j] = max(1, dungeon[i][j+1]-dungeon[i][j]);
                else if (j == n-1)
                    dungeon[i][j] = max(1, dungeon[i+1][j]-dungeon[i][j]);
                else
                    dungeon[i][j] = max(1, min(dungeon[i][j+1], dungeon[i+1][j]) - dungeon[i][j]);
            }
        }
        
        return dungeon[0][0];        
    }
};
