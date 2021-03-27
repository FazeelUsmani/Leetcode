class Solution {
 public:
    int countSubstrings(string s) {
        int n = s.size(), ans = 0;

        if (n <= 0)
            return 0;

        bool dp[n][n];
        fill_n(*dp, n * n, false);

        // Base case: single letter substrings
        for (int i = 0; i < n; ++i, ++ans)
            dp[i][i] = true;

        // Base case: double letter substrings
        for (int i = 0; i < n - 1; ++i) {
            dp[i][i + 1] = (s[i] == s[i + 1]);
            ans += dp[i][i + 1];
        }

        // All other cases: substrings of length 3 to n
        for (int len = 3; len <= n; ++len)
            for (int i = 0, j = i + len - 1; j < n; ++i, ++j) {
                dp[i][j] = dp[i + 1][j - 1] && (s[i] == s[j]);
                ans += dp[i][j];
            }

        return ans;
    }
};
