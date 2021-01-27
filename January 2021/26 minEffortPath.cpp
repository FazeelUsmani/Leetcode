static int _ = []{ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); return 0; }();

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights.front().size();
        
        vector<vector<int>> costs(n, vector<int>(m, INT_MAX));
        costs[0][0] = 0;
        
        queue<pair<int, int>> q;
        q.push({0, 0});
        
        vector<pair<int, int>> steps = {
            {-1, 0},
            {1, 0},
            {0, -1},
            {0, 1}
        };
        
        while(!q.empty()){
            int y0 = q.front().first;
            int x0 = q.front().second;
            
            q.pop();
            
            for (const auto & step : steps){
                int y = y0 + step.first;
                int x = x0 + step.second;

                if (y >= 0 and y < n and x >= 0 and x < m){

                    int cost = max(costs[y0][x0], abs(heights[y][x] - heights[y0][x0]));
                    if (cost < costs[y][x]){
                        costs[y][x] = cost;
                        q.push({y, x});
                    }
                }
            }
        }
        
        return costs.back().back();
    }
};
