class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        
        
        int odd = 0, even = 0;
        for (int &x: A){
            if (x & 1){
                odd++;
            }
            else{
                even++;
            }                
        }
        
        vector<int> res(A.size(), 0);
        
        int oddPtr = A.size()-1, evenPtr = 0;
        for (int &x: A){
            if (x&1){
                res[oddPtr--] = x;
            }
            else{
                res[evenPtr++] = x;
            }
        }
        
        return res;
    }
};
