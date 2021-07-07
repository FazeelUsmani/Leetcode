class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        
        vector<int> ans (nums.size(), nums[0]);
        for (int i = 1; i < nums.size(); ++i) {
            ans[i] = ans[i-1] + nums[i];
        }
        
        return ans;
    }
};
