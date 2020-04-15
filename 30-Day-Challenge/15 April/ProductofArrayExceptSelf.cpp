
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int> preM (n, 0);
        preM[0] = nums[0];
        
        for (int i = 1; i < n; i++)
            preM[i] = preM[i-1] * nums[i];            
        
            
        vector<int> postM (n, 0);
        postM[n-1] = nums[n-1];
        
        for (int i = n-2; i >= 0; i--)
            postM[i] = postM[i+1] * nums[i];
        
        vector<int> ans;
        ans.push_back(postM[1]);
        for (int i = 1; i < n-1; i++)            
            ans.push_back(postM[i+1] * preM[i-1]);
        ans.push_back(preM[n-2]);
        
        return ans;
    }
};
