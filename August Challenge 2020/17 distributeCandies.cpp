class Solution {
public:
    vector<int> distributeCandies(int candies, int n) {
        
        vector<int> ans(n, 0);
        int i = 0, index, curr = 1;
        
        while (candies > 0){
            i = i%n;
            if (candies >= curr){
                candies -= curr;
                ans[i] += curr;
                curr++;
                i++;
            }            
            else{
                ans[i] += candies;
                candies = 0;
            }
        }
        
        return ans;        
    }
};
