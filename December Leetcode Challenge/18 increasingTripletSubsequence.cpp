class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        vector<int> a(2, INT_MAX);
        for(int x: nums) {
            if (x < a[0])   a[0] = x;
            if (x < a[1] && x > a[0])   a[1] = x;
            if (x > a[1])   return true;           
        }
        
        return false;
    }
};
