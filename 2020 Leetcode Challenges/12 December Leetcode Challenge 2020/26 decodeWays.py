class Solution:
    def numDecodings(self, s):
        dp = [1, 0, 0]
        for c in s:
            dp_new = [0,0,0]
            dp_new[0]  = (c > '0') * dp[0] + dp[1] + (c <= '6') * dp[2]
            dp_new[1]  = (c == '1') * dp[0]
            dp_new[2]  = (c == '2') * dp[0]
            dp = dp_new
        return dp[0]
