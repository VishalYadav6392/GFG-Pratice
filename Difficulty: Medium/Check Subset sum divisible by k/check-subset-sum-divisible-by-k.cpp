class Solution {
  public:
    bool divisibleByK(vector<int>& arr, int k) {
        vector<bool> dp(k, false);

        for (int x : arr) {
            vector<bool> nxt = dp;

            // Start a new subset
            nxt[x % k] = true;

            // Extend existing subsets
            for (int r = 0; r < k; r++) {
                if (dp[r]) {
                    nxt[(r + x) % k] = true;
                }
            }

            dp = nxt;

            if (dp[0]) return true;
        }

        return false;
    }
};