bool cmp(vector<int> &a, vector<int> &b) {
        
        return a[0] < b[0];
    }
    

class Solution {
public:
    
    
    vector<vector<int>> merge(vector<vector<int>>& a) {
               
        sort (a.begin(), a.end(), cmp);
        int n = a.size();
        if (n == 0) {
            return {{}};
        }
        vector<vector<int>> ans;
        
        int start = a[0][0], end = a[0][1];
        
        for (int i = 1; i < n; ++i) {
            if (end >= a[i][0]) {                
                end = max(end, a[i][1]);;
            }
            else {
                ans.push_back({start, end});
                start = a[i][0];
                end = a[i][1];
                
            }
        }
        
        ans.push_back({start, end});
        
        return ans;
    }
};
