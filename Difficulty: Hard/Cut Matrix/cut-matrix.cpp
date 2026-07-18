class Solution {
    const int MOD = 1000000007;

public:
    int findWays(vector<vector<int>>& matrix, int k) {

        int rows = matrix.size();
        int cols = matrix[0].size();

        // Suffix count of 1's
        vector<vector<int>> cnt(rows + 1, vector<int>(cols + 1, 0));

        for (int i = rows - 1; i >= 0; i--) {
            for (int j = cols - 1; j >= 0; j--) {
                cnt[i][j] = matrix[i][j]
                          + cnt[i + 1][j]
                          + cnt[i][j + 1]
                          - cnt[i + 1][j + 1];
            }
        }

        vector<vector<vector<int>>> ways(
            rows, vector<vector<int>>(cols, vector<int>(k, 0)));

        // Base case
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                ways[i][j][0] = (cnt[i][j] > 0);
            }
        }

        for (int piece = 1; piece < k; piece++) {

            // Vertical suffix DP
            vector<vector<int>> down(rows + 1, vector<int>(cols, 0));

            for (int j = 0; j < cols; j++) {
                for (int i = rows - 1; i >= 0; i--) {
                    down[i][j] = (down[i + 1][j] + ways[i][j][piece - 1]) % MOD;
                }
            }

            // Horizontal suffix DP
            vector<vector<int>> right(rows, vector<int>(cols + 1, 0));

            for (int i = 0; i < rows; i++) {
                for (int j = cols - 1; j >= 0; j--) {
                    right[i][j] = (right[i][j + 1] + ways[i][j][piece - 1]) % MOD;
                }
            }

            for (int i = rows - 1; i >= 0; i--) {

                for (int j = cols - 1; j >= 0; j--) {

                    if (cnt[i][j] == 0)
                        continue;

                    long long ans = 0;

                    // First valid horizontal cut
                    int low = i + 1, high = rows;

                    while (low < high) {
                        int mid = low + (high - low) / 2;

                        if (cnt[mid][j] < cnt[i][j])
                            high = mid;
                        else
                            low = mid + 1;
                    }

                    if (low < rows)
                        ans = (ans + down[low][j]) % MOD;

                    // First valid vertical cut
                    low = j + 1;
                    high = cols;

                    while (low < high) {
                        int mid = low + (high - low) / 2;

                        if (cnt[i][mid] < cnt[i][j])
                            high = mid;
                        else
                            low = mid + 1;
                    }

                    if (low < cols)
                        ans = (ans + right[i][low]) % MOD;

                    ways[i][j][piece] = ans;
                }
            }
        }

        return ways[0][0][k - 1];
    }
};