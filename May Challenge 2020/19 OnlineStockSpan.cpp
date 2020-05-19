stack <pair<int, int>> s;
class StockSpanner {
public:
    stack<pair<int, int>> s;
    StockSpanner() {
        ios::sync_with_stdio(false);
        cin.tie(0);        
    }
    
    int next(int price) {
        int res = 1;
        while (!s.empty() && s.top().first <= price){
            res += s.top().second;
            s.pop();
        }
        
        s.push({price, res});
        return res;        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
