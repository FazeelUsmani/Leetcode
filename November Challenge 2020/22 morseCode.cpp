class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        
        
        vector<string> morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---",
                                "-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-",
                                "...-",".--","-..-","-.--","--.."};
        
        vector<string> ans;
        for (string x: words) {
            string temp = "";
            for (int i = 0; i < x.size(); ++i) {
                temp = temp + morse[ x[i] - 'a' ];                
            }
            ans.push_back(temp);
        }
        
        unordered_set <string> s;
        for (string k: ans)
            s.insert(k);
        
        return s.size();      
    }
};
