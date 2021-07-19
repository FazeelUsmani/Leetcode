class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& a, int k) {
        
        const int n = a.size();     
        long long p = 1; 
        int res = 0; 
        for (int start = 0, end = 0; end < n; end++) { 

            // Move right bound by 1 step. Update the product. 
            p *= a[end]; 

            // Move left bound so guarantee that p is again  
            // less than k. 
            while (start < end && p >= k)  
                p /= a[start++];         

            // If p is less than k, update the counter. 
            // Note that this is working even for (start == end): 
            // it means that the previous window cannot grow  
            // anymore and a single array element is the only  
            // addendum. 
            if (p < k) { 
                int len = end-start+1; 
                res += len; 
            } 
        } 

        return res; 
        
    }
};
