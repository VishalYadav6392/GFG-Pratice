class Solution {
  public:
    int getCount(int n) {
        // code here
             int count = 0;

        for (long long k = 2; k * (k + 1) / 2 <= n; k++) {
            long long remaining = n - k * (k - 1) / 2;

            if (remaining % k == 0) {
                count++;
            }
        }

        return count;
    }
};