class Solution:
    def kthFactor(self, n, k):
        f1, f2 = [], []
        for s in range(1, int(sqrt(n)) + 1 ):
            if n % s == 0:
                f1 += [s]
                f2 += [n//s]
                
        if f1[-1] == f2[-1]: f2.pop()
            
        factors = f1 + f2[::-1]
        return -1 if len(factors) < k else factors[k-1]
