class Solution {
public:
    int maxPower(string s) {
        
        int n = s.size();
        if (n == 0)
            return 0;
        if (n == 1) 
            return 1;
        
        if (n == 2)
            return ( (s[0]==s[1]) ? 2 : 0);
        
        char x = s[0];
        int cnt = 0;
        for (int i = 1; i < n; ++i) {
            if (s[i] != x)
                break;
            else
                cnt++;
        }
        if (cnt == n)
            return n;
        
        
        int ans = INT_MIN;
        cnt = 1;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == s[i-1]) {
                cnt++;
            }
            else {
                ans = max(ans, cnt);
                cnt = 1;
            }
        }
        
        ans = INT_MIN;
        cnt = 1;
        for (int i = n-2; i >= 0; --i) {
            if (s[i] == s[i+1]) {
                cnt++;
            }
            else {
                ans = max(ans, cnt);
                cnt = 1;
            }
        }
        
        return ans;        
    }
};
