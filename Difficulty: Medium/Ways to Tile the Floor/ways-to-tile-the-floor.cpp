class Solution {
  public:
    int countWays(int n, int m) {
       const int MOD = 1e9 + 7;

        vector<long long> dp(n + 1, 0);

        dp[0] = 1;

        for (int i = 1; i <= n; i++) {
            if (i < m)
                dp[i] = 1;
            else if (i == m)
                dp[i] = 2;
            else
                dp[i] = (dp[i - 1] + dp[i - m]) % MOD;
        }

        return dp[n];
    }
};