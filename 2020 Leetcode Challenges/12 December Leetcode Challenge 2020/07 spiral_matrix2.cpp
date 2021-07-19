class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
         
        int cnt = 1;
        vector<vector<int>> ans(n, vector<int> (n));
        
        for (int layer = 0; layer < (n+1)/2; layer++) {
            
            for (int ptr = layer; ptr < n-layer; ptr++) {
                ans[layer][ptr] = cnt++;
            }
            for (int ptr = layer+1; ptr < n-layer; ptr++) {
                ans[ptr][n-layer-1] = cnt++;
            }
            for (int ptr = n-layer-2; ptr >= layer; ptr--) {
                ans[n-layer-1][ptr] = cnt++;
            }
            for (int ptr = n-layer-2; ptr > layer; ptr--) {
                ans[ptr][layer] = cnt++;
            }
        }
        
        return ans;        
    }
};
