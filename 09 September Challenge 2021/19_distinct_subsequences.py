class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        @lru_cache(None)
        def dp(i, j):
            if j == 0: return 1  # Case t = "", there is a valid subsequence which is empty string.
            if i == 0: return 0
            ans = dp(i - 1, j)
            if s[i-1] == t[j-1]:
                ans += dp(i - 1, j - 1)
            return ans

        return dp(len(s), len(t))