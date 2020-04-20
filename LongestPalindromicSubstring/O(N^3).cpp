bool isPalin(string s){
    string rev = s;
    reverse(rev.begin(), rev.end());
    return s == rev;
}

class Solution {
public:
    string longestPalindrome(string s) {
        
        int n = s.length();
        int best_len = 0;
        string best_s = "";
        for (int i = 0; i < n; i++){
            for (int j = i; j < n; j++){
                int len = j - i + 1;
                string subs = s.substr(i, len);
                if (len > best_len && isPalin(subs)){                    
                    best_len = len;
                    best_s = subs;
                }
            }
        }
        return best_s;        
    }
};
