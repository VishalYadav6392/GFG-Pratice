class Solution {
  public:
    int maxDotProduct(vector<int>& a, vector<int>& b) {
        // code here
        int n = a.size();
        int m = b.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MIN));

        dp[0][0] = 0;

        for (int i = 1; i <= n; i++) {
            dp[i][0] = 0; // match no elements of b
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= min(i, m); j++) {
                dp[i][j] = max(
                    dp[i - 1][j],
                    dp[i - 1][j - 1] + a[i - 1] * b[j - 1]
                );
            }
        }

        return dp[n][m];
    }
};
