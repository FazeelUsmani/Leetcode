class Solution {
public:
   
    string frequencySort(string s) {
        
        int Count[256]={};
        
        for(auto i:s)        Count[i]++;    
           
        sort(s.begin(),s.end(),[&Count](char &a, char &b)
             {
                 return (Count[a] != Count[b]) ? Count[a] > Count[b] : a<b;    
             });
        return s;
        
    }
};
