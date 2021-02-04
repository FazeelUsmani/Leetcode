class Solution {
public:
    int findLHS(vector<int>& nums) {
        
        unordered_map<int, int> umap;
        
        for (int x: nums) {
            umap[x]++; 
        }
        
        int ans = 0;
        for (int x: nums) {
            if (umap.find(x+1) != umap.end()) {
                ans = max(ans, umap[x] + umap[x+1]);
            }
        }
        
        return ans;
    }
};
