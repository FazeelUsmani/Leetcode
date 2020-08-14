class Solution {
public:
    int longestPalindrome(string s) {
        
        int cnt[256] = {0};
        
        for (char &x: s)
            cnt[x]++;
        
        int ans = 0;
        bool odd = false;
        for (int i = 0; i < 256; ++i){
            if (cnt[i] == 0)
                continue;
            
            if (cnt[i] & 1){
                odd = true;
                ans += cnt[i]-1;
            }
            else{
                ans += (cnt[i]);
            }           
        }
        if (odd)
            ans++;
        
        
        return ans;
    }
};
