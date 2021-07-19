class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        
               
        s=s.strip()
        s=s.split()
        
        if (len(s) == 0):
            return 0;
        
        return len(s[-1])
        
