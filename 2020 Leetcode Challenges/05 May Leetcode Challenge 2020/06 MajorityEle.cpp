class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int n = nums.size();
        n /= 2;
        unordered_map <int, int> freq;
        for (auto x : nums)
            freq[x]++;
        
        int ans = 0;
        for (auto i : freq)
            if (i.second > n)         
                ans = i.first;
        
        return ans;        
    }
};
