      
class Solution:
    
    def transformString(self, s: str) -> str:
        
        index_mapping = {}
        new_str = []
        
        for i, c in enumerate(s):
            
            if c not in index_mapping:
                index_mapping[c] = i
                
            new_str.append(str(index_mapping[c]))
        
        return "".join(new_str)
    
    def isIsomorphic(self, s: str, t: str) -> bool:
        return self.transformString(s) == self.transformString(t)
