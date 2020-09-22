class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int n = nums.size();
        if (n == 0)
            return {};
        
        int cnt1 = 0, cnt2 = 0;
        int maj1 = 0, maj2 = 0;
        
        for (int x: nums) {
            if (maj1 == x)      
                cnt1++;
            else if (maj2 == x)     
                cnt2++;
            else if (cnt1 == 0){
                maj1 = x;
                cnt1 = 1;
            }
            else if (cnt2 == 0){
                maj2 = x;
                cnt2 = 1;
            }
            else {
                cnt1--;
                cnt2--;
            }
        }
        
        vector<int> result;
        int c1 = 0, c2 = 0;
        for (int x: nums){
            if (x == maj1)      
                c1++;
            else if (x == maj2)       
                c2++;
        }
        
        if (c1 > n/3)
            result.push_back(maj1);
        if (c2 > n/3)
            result.push_back(maj2);
        
        return result;
    }
};
