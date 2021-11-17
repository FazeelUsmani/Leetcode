class Solution {
public:
    int uniquePaths(int A, int B) {
        if ((A == 1) || (B == 1))
            return 1;
        if (A > B)
            swap(A, B);
        long long res = 1;
        int j = 1;
        for (int i = A; i < A+B-2+1; i++){
            res *= i;
            res /= j;
            j += 1;            
        }
        
        return res;              
    }
};
