class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        int n = nums.size();
        int *arr = new int[2*n+1];
        
        for (int i = 0; i < 2*n+1; i++)
            arr[i] = -1;
        
        int mid = n;
        int cnt = 0, ans = 0;
        
        for (int i = 0; i < n; i++){
            if (nums[i] == 0){
                cnt--;
            }
            else{
                cnt++;
            }
            
            if (cnt == 0){
                ans = i+1;
            }
            else if (arr[mid+cnt] == -1){
                arr[mid+cnt] = i;
            }
            else{
                ans = max (ans, i - arr[mid+cnt]);                
            }
        }
        
        return ans;              
    }
};
