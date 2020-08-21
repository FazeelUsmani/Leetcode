bool myCmp(int a, int b){
    a = a%2;
    b = b%2;
    return a < b;
}

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        
        sort(A.begin(), A.end(), myCmp);
        
        return A;        
    }
};
