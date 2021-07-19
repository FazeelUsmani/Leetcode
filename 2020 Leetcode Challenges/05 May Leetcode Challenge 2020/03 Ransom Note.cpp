class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        int a[256] = {0};
        int b[256] = {0};
        
        for (auto x : ransomNote)
            a[x]++;
        
        for (auto y : magazine)
            b[y]++;
        
        for (int i = 97; i < 123; i++)
            if (b[i] < a[i])
                return false;
        
        return true;       
        
    }
};
