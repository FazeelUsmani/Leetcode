class Solution {
public:
    bool isAnagram(string s, string t) {
                
        int cnt[256] = {0}, cnt1[256] = {0};
        
        for (char a: s)
            cnt[a]++;
        
        for (char b: t)
            cnt1[b]++;
        
        for (int i = 0; i < 256; ++i) {
            if (cnt[i] != cnt1[i]) {
                return false;
            }
        }
        
        return true;
    }
};
