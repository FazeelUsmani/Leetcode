class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        
        int last = -100000;
        
        for (int i = 0; i < nums.size(); ++i) {
            
            if (nums[i]) {
                if ((i-last) <= k) {
                    return false;
                }          
                last = i;
            }
        }
        
        return true;
    }
};
