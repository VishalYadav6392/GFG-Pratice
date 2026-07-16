class Solution {
public:
    int dp[10][82];

    int solve(int pos, int n, int sum) {
        if (pos == n)
            return sum == 0;

        if (dp[pos][sum] != -1)
            return dp[pos][sum];

        int ans = 0;

        int start = (pos == 0) ? 1 : 0;

        for (int d = start; d <= 9 && d <= sum; d++)
            ans += solve(pos + 1, n, sum - d);

        return dp[pos][sum] = ans;
    }

    int countWays(int n, int sum) {
        if (sum > 9 * n)
            return -1;

        memset(dp, -1, sizeof(dp));

        int ans = solve(0, n, sum);

        return ans == 0 ? -1 : ans;
    }
};