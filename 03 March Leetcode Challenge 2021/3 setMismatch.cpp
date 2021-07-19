class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        
        unordered_set <int> uset;
        vector<int> ans;
        for (int x: nums){
            if (uset.find(x) != uset.end()) {
                ans.push_back(x);
            }
            else {
                uset.insert(x);
            }
        }
        
        int i;
        for(i = 1; i <= nums.size(); ++i){
            if (uset.find(i) == uset.end()){
                ans.push_back(i);
            }
        }
        
        
        return ans; 
    }
};
