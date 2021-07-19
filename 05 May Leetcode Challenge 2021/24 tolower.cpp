class Solution {
public:
    string toLowerCase(string s) {
        
        string res = "";
        for (char x: s) {
            if (x >= 65 && x <= 90) {
                res.push_back(x+32);
            }else {
                res.push_back(x);
            }
        }
            
        return res;
        
    }
};
