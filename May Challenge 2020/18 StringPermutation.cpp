
bool check (int A[26], int B[26]){
    for (int i = 0; i <26; i++){
        if (A[i] != B[i]){
            return false;
        }
    }
    return true;
}

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
                
        int freq1[26] {0}, freq2[26] {0};
        int lenS1 = s1.length(), lenS2 = s2.length();
        if (lenS1 > lenS2)
            return false;

        for (int i = 0; i < lenS1; i++){
            freq1[s1[i]-'a']++;
            freq2[s2[i]-'a']++;
        }
        
        if (check(freq1, freq2))
                return true;
            
        
        for (int j = lenS1; j < lenS2; j++){
            
            freq2[ s2[j-lenS1] - 'a' ]--;
            freq2[s2[j] - 'a']++;
            
            if (check(freq1, freq2))
                return true;            
        }
        
        return false;
        
        
    }
};
