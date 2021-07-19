class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        int n = nums.size();
        for (int i = 0; i < n; ++i){
            if (nums[i] == 0){
                nums[i] = -1;
            }
        }
        
        vector<int> prefix;        
        prefix.push_back(0);
        for (int x : nums){
            prefix.push_back(prefix.back() + x);
        }
        
        int ans = 0;        
        unordered_map<int , int> first_oc;
        for (int i = 0; i < (int) prefix.size(); ++i){
            int x = prefix[i];
            auto it = first_oc.find(x);
            
            if (it != first_oc.end()){
                ans = max(ans, i - first_oc[x]);
            }
            else{
                first_oc[x] = i;
            }
        }
    
        return ans;
    }
};
