class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        int ls = s.length();
        int lt = t.length();
        int cnt = 0;
        
        int start = 0, j;
        for (int i = 0; i < ls; i++){
            
            j = start;
            while (j < lt)
            {
                if (s[i] == t[j]){
                    start = j+1;
                    cnt++;
                    break;
                }
                else
                    j++;
            }
            
        }
        
        if (cnt == ls)
            return true;
        return false;
        
    }
};
