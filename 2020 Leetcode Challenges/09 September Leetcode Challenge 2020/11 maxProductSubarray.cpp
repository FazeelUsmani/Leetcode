class Solution {
public:
    int maxProduct(vector<int>& A) {
        
        int n = A.size();
        if (n == 1)
            return A[0];
        
        int ans = A[0];
        int pos = A[0], neg = A[0];
        for (int i = 1; i < n; ++i){
            if (A[i] < 0)
                swap(pos, neg);
            
            pos = max(A[i], A[i]*pos);
            neg = min(A[i], A[i]*neg);
            ans = max(ans, pos);
        }
        
        return ans;        
    }
};
