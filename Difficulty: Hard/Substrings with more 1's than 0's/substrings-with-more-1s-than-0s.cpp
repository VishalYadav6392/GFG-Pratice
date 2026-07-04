class Solution {
  public:
    int countSubstring(string& s) {
      int n = s.size();
        int offset = n + 1;

        vector<long long> freq(2 * n + 3, 0);

        long long ans = 0;
        long long dp = 0;

        int prefix = 0;

        // Empty prefix
        freq[offset] = 1;

        for (char ch : s) {

            if (ch == '1') {
                // prefix changes from x to x + 1
                // Prefix sums equal to x now become smaller
                dp += freq[prefix + offset];
                prefix++;
            }
            else {
                // prefix changes from x to x - 1
                prefix--;

                // Prefix sums equal to new prefix
                // are not smaller anymore
                dp -= freq[prefix + offset];
            }

            // dp = valid substrings ending here
            ans += dp;

            // Store current prefix
            freq[prefix + offset]++;
        }

        return ans;
    }
};