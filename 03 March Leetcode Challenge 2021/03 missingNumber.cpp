class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int n = nums.size();
        long long ans = (n*(n+1))/2;
        
        for (int x: nums) {
            ans -= x;
        }
        
        return ans;
    }
};
