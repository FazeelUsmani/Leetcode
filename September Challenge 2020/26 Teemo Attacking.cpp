class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        
        if (timeSeries.size() == 0)    return 0;
        if (timeSeries.size() == 1)    return duration;
        
        int total = 0;
        for (int i = 1; i < timeSeries.size(); ++i)
            total += min(duration, timeSeries[i]-timeSeries[i-1]);
        
        total += duration;
        
        return total;        
    }
};
