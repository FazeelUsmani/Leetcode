class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int, int> m;
        vector<vector<int>> res;
       
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size(); i++) 
            m[nums[i]] = i;
        
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            
            for (int j = i+1; j < nums.size(); j++) {
                if (j != i+1 && nums[j] == nums[j-1]) continue;
                
                if (m[-(nums[i] + nums[j])] > j) 
                    res.push_back({nums[i], nums[j], -(nums[i] + nums[j])});
                
            }
        }
        return res;
    }
};
