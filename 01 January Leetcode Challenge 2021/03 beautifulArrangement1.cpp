class Solution {
public:
    int cnt = 0;
    void calculate(int n, int pos, vector<bool> &visited) {
        if (pos > n) {
            cnt++;
        }    
        for (int i = 1; i <= n; ++i) {
            if (!visited[i] && (((pos%i) == 0) || ((i%pos) == 0))) {
                visited[i] = true;
                calculate(n, pos+1, visited);
                visited[i] = false;
            }   
        }      
    }
    
    int countArrangement(int n) {
        cnt = 0;
        vector<bool> visited (n+1, false);
        calculate(n, 1, visited);
        
        return cnt;        
    }
};
