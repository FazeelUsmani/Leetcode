class Solution {
public:
    bool isPalindrome(string s) {
        
        string modifiedString;
        for (int i = 0; i < s.length(); ++i){
            if (isdigit(s[i])){
                modifiedString.push_back(s[i]);
            }
            else if(isupper(s[i]) || islower(s[i])){
                modifiedString.push_back(tolower(s[i]));
            }            
        }
        
        int i = 0, j = modifiedString.length() - 1;
        
        while (i < j){
            if (modifiedString[i] != modifiedString[j]){
                return false;
            }
            i++;
            j--;
        }
        
        return true;
    }
};
