class Solution {
public:
    int cntBits(int n){
        
        int cnt = 0;
        while (n > 0){
            n = n & (n-1);
            cnt++;
        }
        return cnt;
    }
    
    vector<int> countBits(int num) {
        
        vector<int> ans;
        
        for (int i = 0; i <= num; i++){
            ans.push_back(cntBits(i));            
        }
        
        return ans;
    }
};
