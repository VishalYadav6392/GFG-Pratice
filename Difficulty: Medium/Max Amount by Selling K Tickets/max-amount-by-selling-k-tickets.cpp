class Solution {
public:
    int maxAmount(vector<int>& arr, int k) {
        const long long MOD = 1e9 + 7;

        sort(arr.rbegin(), arr.rend());

        int n = arr.size();
        long long ans = 0;

        for (int i = 0; i < n && k > 0; i++) {
            long long current = arr[i];
            long long next = (i + 1 < n) ? arr[i + 1] : 0;

            long long sellers = i + 1;
            long long diff = current - next;

            long long tickets = sellers * diff;

            if (tickets <= k) {
                long long sum = (current + next + 1) * diff / 2;

                ans = (ans + (sum % MOD) * sellers) % MOD;

                k -= tickets;
            }
            else {
                long long levels = k / sellers;
                long long remaining = k % sellers;

                long long low = current - levels;

                long long sum = (current + low + 1) * levels / 2;

                ans = (ans + (sum % MOD) * sellers) % MOD;

                ans = (ans + remaining * low) % MOD;

                k = 0;
            }
        }

        return ans;
    }
};