class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        
        int odd = 0, even = 0;
        
        for (int x: position){
            if (x & 1)
                odd++;
            else
                even++;
        }
        
        
        return min(odd, even);
    }
};
