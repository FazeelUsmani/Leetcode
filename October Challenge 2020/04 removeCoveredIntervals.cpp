class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        
        int result = 1;
        sort(intervals.begin(), intervals.end());
        int x1 = intervals[0][0], x2 = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[i][0] > x1 && intervals[i][1] > x2) result++;
            if(intervals[i][1] > x2) {
                x1 = intervals[i][0];
                x2 = intervals[i][1];
            }
        }
        
        return result;        
    }
};
