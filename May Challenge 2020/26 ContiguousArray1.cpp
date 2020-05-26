class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        int n = nums.size();
        int cnt = 0, ans = 0;
        
        unordered_map <int, int> index;
        
        for (int i = 0; i < n; i++){
            if (nums[i] == 1)
                cnt++;
            else
                cnt--;
            
            if (cnt == 0)
                ans = i+1;
            if (index.find(cnt) == index.end())
                index[cnt] = i;
            else
                ans = max(ans, i-index[cnt]);
        }
        
        return ans;        
    }
};
