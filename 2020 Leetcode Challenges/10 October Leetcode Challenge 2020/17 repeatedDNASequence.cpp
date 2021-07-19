class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        
        vector<string> res;
        unordered_map <string, int> umap;
        
        if (s.length() <= 10)
            return res;
        
        for (int i = 0; i <= s.length() - 10; ++i) {
            umap[s.substr(i, 10)]++;
        }
        
        for (auto x: umap) {
            if (x.second > 1) {
                res.push_back(x.first);
            }
        }
        
        return res;
    }
};
