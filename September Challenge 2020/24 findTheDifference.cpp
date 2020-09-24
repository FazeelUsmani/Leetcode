class Solution {
public:
    char findTheDifference(string s, string t) {
        
        if (s.size() == 0 && t.size() != 0) {
            return t[0];
        }
        
        int cnt[256] = {0};
        for (char x: s) {
            cnt[x]++;            
        }
        
        for (char x: t) {
            cnt[x]--;            
        }
        
        int p = 0;
        for (int i = 0; i < 256; ++i) {
            if (cnt[i] != 0) {
                p = i;             
            }
        }
        return char(p);
    }
};
