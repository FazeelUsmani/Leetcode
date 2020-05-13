class Solution {
public:
    string removeKdigits(string num, int k) {
        
        if (num.length() == k)
            return "0";
        
        for (int j = 0; j < k; j++){
            int i = 0;
            while (i < num.length()-1 && num[i] <= num[i+1])
                i++;
            num.erase(num.begin()+i);
        }
        
        while (num.length() > 1 && num[0] == '0')
            num.erase(num.begin());
        
        if (!isdigit(num[0]))
            return "0";
        return num;        
        
    }
};
