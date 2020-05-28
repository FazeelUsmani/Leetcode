class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans(num+1,0);
        for (int i = 1; i <= num; i++)
            ans[i] = ans[i/2] + i%2;
        
        return ans;
    }
};
