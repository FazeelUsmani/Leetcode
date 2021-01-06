class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        
        int cnt = 0;        
        int i = 0;
        int required = 1;
        int n = arr.size();
        
        while (i < n) {
            while (arr[i] != required) {
                cnt++;                
                if (cnt == k)
                    return required;
                required++;
            }
            required++;
            i++;          
        }        
        
        required--;
        while (cnt != k) {
            cnt++;
            required++;
        }
        
        return required;
    }
};
