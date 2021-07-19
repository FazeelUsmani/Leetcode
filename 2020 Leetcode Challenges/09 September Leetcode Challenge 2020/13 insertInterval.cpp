class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        vector<vector<int>> res;
        
        for (vector<int> x: intervals) {
            
            if (x[1] < newInterval[0]){
                res.push_back(x);
            }
            else if (x[0] > newInterval[1]){
                res.push_back(newInterval);
                newInterval = x;
            }
            else if ( (x[1] >= newInterval[0]) || (x[0] <= newInterval[1]) ) {
                newInterval[0] = min(x[0], newInterval[0]);
                newInterval[1] = max(x[1], newInterval[1]);
            }
        }
        
        res.push_back(newInterval);
        
        return res;                
    }
};
