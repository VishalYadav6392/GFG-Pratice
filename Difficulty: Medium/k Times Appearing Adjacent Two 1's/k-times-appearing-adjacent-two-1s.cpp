class Solution {
public:
    static const int MOD = 1000000007;

    int countStrings(int n, int k) {

        vector<vector<long long>> prev(k + 1, vector<long long>(2, 0));
        vector<vector<long long>> cur(k + 1, vector<long long>(2, 0));

        prev[0][0] = 1;
        prev[0][1] = 1;

        for (int i = 2; i <= n; i++) {

            for (int j = 0; j <= k; j++) {

                cur[j][0] = (prev[j][0] + prev[j][1]) % MOD;

                long long ways = prev[j][0];

                if (j > 0)
                    ways = (ways + prev[j - 1][1]) % MOD;

                cur[j][1] = ways;
            }

            swap(prev, cur);

            // reset current row
            for (int j = 0; j <= k; j++)
                cur[j][0] = cur[j][1] = 0;
        }

        return (prev[k][0] + prev[k][1]) % MOD;
    }
};