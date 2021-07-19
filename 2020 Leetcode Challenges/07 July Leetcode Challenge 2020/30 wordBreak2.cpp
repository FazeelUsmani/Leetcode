class Solution {
public:
    map <string, vector<string>> dp;
    
    vector<string> ff(string s, set<string>& word_dict) {
        vector<string> res;
        if (dp.find(s) != dp.end()) return dp[s];
        
        for (int i = 1; i <= s.size(); i++) {
            if (word_dict.find(s.substr(0, i)) != word_dict.end()) {
                if (s.substr(i).length() == 0) {
                    res.push_back(s.substr(0, i));
                }
                else {
                    vector<string> subList = ff(s.substr(i), word_dict);
                    for (auto sub : subList) res.push_back(s.substr(0, i) + " " + sub);
                }
            }
        }
        
        return dp[s] = res;
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        set <string> word_dict(wordDict.begin(), wordDict.end());
        return ff(s, word_dict);
    }
};
