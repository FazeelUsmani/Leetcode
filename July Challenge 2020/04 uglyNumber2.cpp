#define ll long long

class Solution {
public:
    int nthUglyNumber(int n) {
        
        priority_queue <ll, vector<ll>, greater<ll> > pq;
        unordered_set <ll> s;
        pq.push(1);
        s.insert(1);
        
        while (!pq.empty() && n > 0){
            
            ll top = pq.top();
            pq.pop();
            n--;
            
            if (n == 0)
                return top;
            
            else{
                if (s.find(top*2) == s.end()){
                    pq.push(top*2);
                    s.insert(top*2);
                }
                if (s.find(top*3) == s.end()){
                    pq.push(top*3);
                    s.insert(top*3);
                }
                if (s.find(double(top*5)) == s.end()){
                    pq.push(top*5);
                    s.insert(top*5);
                }
            }           
        }
        
        return -1;        
    }
};
