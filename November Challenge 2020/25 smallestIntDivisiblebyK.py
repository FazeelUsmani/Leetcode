class Solution:
    def smallestRepunitDivByK(self, K: int) -> int:        
        
        if K % 10 not in {1, 3, 7, 9}: return -1
        
        MOD, MOD_SET = 0, set()
        
        for length in range(1, K + 1):
            MOD = (10 * MOD + 1) % K
            if MOD == 0:    return length
            if MOD in MOD_SET:  return -1
            MOD_SET.add(MOD)
            
        return -1
            
