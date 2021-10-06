class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        unordered_map<int, int> freq;
        
        for (int x: nums) {
            freq[x]++;
        }
        
        vector<int> ans;
        for (pair<int, int> f: freq) {
            if (f.second > 1) {
                ans.push_back(f.first);
            }
        }
        
        return ans;
    }
};
