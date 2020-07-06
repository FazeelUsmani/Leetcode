class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        int i = digits.size()-1;
        int plusOne = 1, carry = 0, curr = 0;
        vector<int> ans(digits.size(), 0);
        
        while (i >= 0){
            
            curr = carry + digits[i];
            carry = 0;
            if (plusOne == 1){
                curr += 1;
                plusOne = 0;
            }
            
            if (curr > 9){
                carry = 1;
                ans[i] = 0;
            }           
            else{
                ans[i] = curr;
            }          
            --i;
        }
        
        
        if (carry == 1){
            vector<int> res;
            res.push_back(1);
            
            for (int i = 0; i < ans.size(); ++i)
                res.push_back(ans[i]);
            
            return res;
        }
            
        
        return ans;
    }
};
