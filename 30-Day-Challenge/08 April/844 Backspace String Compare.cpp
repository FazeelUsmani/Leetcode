class Solution {
public:
    bool backspaceCompare(string S, string T) {
       
        
        for (auto i : S){
        if ( i == '#'){
            if (!s1.empty()){
                s1.pop();    
            }
        }      
        else
            s1.push(i);
        }    

        for (auto i : T){
            if (i == '#'){
                if (!s2.empty()){
                    s2.pop();
                }
            }
            else
                s2.push(i);
        }
                
        if (s1 == s2)
            return true;
        return false;
        
    }
};
