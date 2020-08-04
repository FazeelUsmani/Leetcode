class Solution {
public:
    bool isPowerOfFour(int num) {
        
        if(num == 1){
            return true;
        }
        while(num > 4){
            num = num%4 == 0 ? num/4 : 0 ;
        }
        return (num == 4 ? true : false);
        
    }
};
