class Solution:
    def numJewelsInStones(self, J: str, S: str) -> int:
        
        dict = {}
        for i in J:
            dict[i] = 1
        
        cnt = 0
        for k in S:
            if k in dict:
                cnt += 1
                
                
        return cnt
            
            
        
