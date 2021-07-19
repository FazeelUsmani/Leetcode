class Solution:
    def reverseWords(self, s: str) -> str:
        
        x = s.split()
        
        for i in x:
            i = i[::-1]
        
        x = x[::-1]
            
        return (' ').join(x)
        
