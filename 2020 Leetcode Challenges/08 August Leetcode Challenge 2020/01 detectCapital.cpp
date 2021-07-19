class Solution {
public:    
    bool detectCapitalUse(string word) {
        int n = word.length();
        
        int upper = 0, lower = 0;
        for (int i = 0; i < n; ++i){
            if (word[i] >= 97 && word[i] <= 122){
                lower++;
            }
            else if (word[i] >= 65 && word[i] <= 90){
                upper++;
            }
        }
        
        if (upper == n || lower == n)
            return true;
        
        if (upper == 1 && lower == n-1 && (word[0] >= 65 && word[0] <= 90))
            return true;
        
        return false;            
    }
};
