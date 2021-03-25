class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        stack<int> stack;
        int n = s.size();
        
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') 
                stack.push(i);
            
            else if (s[i] == ')') {
                
                if (!stack.empty()) {
                    stack.pop();
                }
                // Deleting extra ) on the fly
                else {
                    s.erase(i);
                    i--;
                }
            }
        }
        
        // Deleting extra ( here
        while (!stack.empty()) {
            s.erase(stack.top());
            stack.pop();
        }
        return s;
        
    }
};
