bool myCmp(vector<int> &a, vector<int> &b){
    return a[1]<b[1];
}

class Solution {
public:      
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        if(intervals.size() == 0)
            return 0;
        
        sort(intervals.begin(), intervals.end(), myCmp);        
        
        int ans = -1;
        vector<int> prev = intervals[0];
        
        for (vector<int> i: intervals){
            if (prev[1]>i[0])
                ans++;
            else
                prev = i;
        }
        
        return (ans==-1) ? 0 : ans;        
    }
};
