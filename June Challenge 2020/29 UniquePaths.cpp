class Solution:
    def uniquePaths(self, A: int, B: int) -> int:
        
        if A == 1 or B == 1:
            return 1

        if A<B:
            A,B = B,A

        res = 1
        j = 1

        for i in range(A, A+B-2+1, 1):
            res *= i
            res //= j
            j += 1

        return res
        
        
