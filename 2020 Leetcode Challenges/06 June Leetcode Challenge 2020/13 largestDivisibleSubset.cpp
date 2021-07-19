class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        //time complexity of my approach is O(n^2)
        int n = nums.size();
        if(n == 0 || n == 1)    return nums;
        
        sort(nums.begin(),nums.end());
        
        vector<int> dp(n,1);
        int maxEle = INT_MIN;
        
        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(nums[i]%nums[j] == 0){
                    int t = 1 + dp[j];
                    if(t > dp[i])   dp[i] = t;
                }
            }
            if(dp[i] > maxEle)  maxEle = dp[i];
        }
        
        vector<int> v;
        
        for(int i=n-1;i>=0;i--){
            if(dp[i] == maxEle){
                v.push_back(nums[i]);
                maxEle--;
            }
        }
        
        
        
        return v;
    }
};
