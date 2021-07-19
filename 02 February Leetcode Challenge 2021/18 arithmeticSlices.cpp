class Solution {
public:
    int sum = 0;
    int recurse (vector<int> &A, int i) {
        
        if (i < 2)
            return 0;
        int ap = 0;
        
        if ((A[i]-A[i-1]) == (A[i-1]-A[i-2])) {
            ap = 1 + recurse(A, i-1);
            sum += ap;
        }
        else 
            recurse(A, i-1);
        
        return ap;
    }
    
    int numberOfArithmeticSlices(vector<int>& A) {
        
        sum = 0;
        recurse(A, A.size()-1);
        
        return sum;        
    }
};
