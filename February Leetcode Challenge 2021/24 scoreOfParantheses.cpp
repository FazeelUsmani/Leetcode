class Solution {
public:
    int scoreOfParentheses(string S) {
        
        int ans = 0, bal = 0;
        for (int i = 0; i < S.size(); ++i) {
            if (S[i] == '(')
                bal++;
            else {
                bal--;
                if (S[i-1] == '(') {
                    ans = ans + (1<<bal);
                }
            }
        }
        
        return ans;       
    }
};
