class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        if (nums.size() == 0)
            return {0,0};
        
        int xor1 = nums[0];
        for (int i = 1; i < nums.size(); ++i){
            xor1 ^= nums[i];
        }
            
        // Finidng first set bit in xor1
        int setBit = 0;
        for (int i = 0; i < 32; ++i){
            if ((1&(xor1>>i)) == 1){
                setBit = i;
                break;
            }
        }
    
        vector<int> Arr1, Arr0;
        for (int x : nums){
    
            if ( (1&((x>>setBit) & (xor1>>setBit))) == 1){
                Arr1.push_back(x);
            }
            else{
                Arr0.push_back(x);
            }
        }
    
        vector<int> ans;
        int s, t;
        if (Arr1.size() != 0){
            s = Arr1[0];
            for (int i = 1; i < Arr1.size(); ++i)
                s ^= Arr1[i];
        }
        
        if (Arr0.size() != 0){
            t = Arr0[0];
            for (int i = 1; i < Arr0.size(); ++i)
                t ^= Arr0[i];
        }
        
        ans.push_back(s);
        ans.push_back(t);
        
        return ans;
    }    
};
