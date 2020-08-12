class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        vector<int> ans(rowIndex+1);
        ans[0] = 1;
        for(int index=1; index<rowIndex+1; index++)
            ans[index]=(long)ans[index-1]*(rowIndex-index+1)/index;
        
        return ans;            
    }
};
