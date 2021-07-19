int gcd(int a, int b){
    if (b == 0)
        return a;
    return gcd(b, a%b);
}

pair<int,int> slope (int x1, int y1, int x2, int y2){
    int num = (y2-y1);
    int den = (x2-x1);
    
    int g = gcd(num, den);
    num /= g;
    den /= g;
    
    return make_pair(num, den);
}

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        
        int n = coordinates.size();
        int num, den;
        if (n <= 2)
            return true;
        
        for (int i = 0; i < n-1; i++){
                
                int x1 = coordinates[i][0];
                int y1 = coordinates[i][1];
            
            for (int j = i+1; j < n; j++){
                
                
                int x2 = coordinates[j][0];
                int y2 = coordinates[j][1];

                if (j == i+1){
                    pair<int, int> s = slope(x1,y1,x2,y2);
                    num = s.first;
                    den = s.second;
                }
                else{
                    pair<int, int> s = slope(x1,y1,x2,y2);
                    int num1 = s.first;
                    int den1 = s.second;     
            
                    if ((num1 != num) || (den1 != den))
                        return false;
                }                                
            }                
        }
        
        return true;        
    }
};
