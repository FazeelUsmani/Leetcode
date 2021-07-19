class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        int letter[26] = {0};
        for(char c : p) letter[c - 'a']++;
        
        vector<int> res;
        int remaining = p.size(), j = 0;
        
        for(int i = 0; i< s.size(); i++){
            
            while(j < s.size() && j - i < p.size()){
                if(letter[s.at(j++) - 'a']-- > 0)
                    remaining--;
            }
            
            if(remaining == 0 && j - i == p.size()) 
                res.push_back(i);
            
            if(letter[s.at(i) - 'a']++ >= 0) 
                remaining++;            
        }
        return res;
        
    }
};
