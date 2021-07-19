class Solution:
    def maxProduct(self, words: List[str]) -> int:
        n = len(words)
        bitmask = [0] * n
        for i in range(n):
            for c in words[i]:
                bitmask[i] |= 1 << (ord(c) - ord('a'))
                
        ans = 0
        for i in range(n):
            for j in range(i+1, n):
                if (bitmask[i] & bitmask[j]) == 0:
                    ans = max(ans, len(words[i]) * len(words[j]))
        return ans
