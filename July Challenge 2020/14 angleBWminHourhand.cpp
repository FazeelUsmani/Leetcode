class Solution {
public:
    double angleClock(int hour, int minutes) {
        
        return min(abs(30*hour - 5.5*minutes), 360-abs(30*hour - 5.5*minutes));
    }
};
