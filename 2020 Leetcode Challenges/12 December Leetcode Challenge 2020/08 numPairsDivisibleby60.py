class Solution:
    def numPairsDivisibleBy60(self, time: List[int]) -> int:
        
        from collections import Counter
        total = 0
        counts = Counter ([x%60 for x in time])
        
        if 30 in counts:
            total += counts[30] * (counts[30] - 1) / 2
            del counts[30]
        if 0 in counts:
            total += counts[0] * (counts[0] - 1) / 2
            del counts[0]
        
        for i in range(1, 30):
            if i in counts and (60-i) in counts:
                total += counts[i] * counts[60-i]
                
        return int(total)
