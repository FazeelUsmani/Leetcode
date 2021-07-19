class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int buy, buyPre = INT_MIN;
        int sell = 0, sellPre1 = 0, sellPre2 = 0;
        
        for (int p: prices){
            buy = max(buyPre, sellPre2-p);
            sell = max(sellPre1, buyPre+p);
            
            buyPre = buy;
            sellPre2 = sellPre1;
            sellPre1 = sell;
        }
        return sell;        
    }
};
