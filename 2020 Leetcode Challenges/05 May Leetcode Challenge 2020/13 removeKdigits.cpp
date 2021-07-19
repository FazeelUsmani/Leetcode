

void insert(deque<char> &dq, char ch){
    
    if (dq.empty())
        dq.push_back(ch);
    else{
        char temp = dq.back();
        while (temp > ch && !dq.empty()){
            dq.pop_back();
            if (!dq.empty()){
                temp = dq.back();
            }
        }
        dq.push_back(ch);
    }
    
    return;    
}

class Solution {
public:
    string removeKdigits(string num, int k) {
        
        int len = num.length();
        int n = len - k;
        
        deque <char> dq;
        string res = "";
        
        int i; 
        for (i = 0; i <= len-n; i++)
            insert(dq, num[i]);
        
        while (i < len){
            res += dq.front();
            dq.pop_front();
            insert(dq, num[i]);
            i++;
        }
        
        res += dq.front();
        dq.pop_front();
        
        while (res[0] == '0')
            res.erase(res.begin());
        
        if (res.size() <= 1 && !isdigit(res[0]))
            return "0";
        
        return res;        
    }
};
