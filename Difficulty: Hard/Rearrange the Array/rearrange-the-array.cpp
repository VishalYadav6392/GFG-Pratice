class Solution {
  public:
    int minOperations(vector<int> &b) {
        const long long MOD = 1e9 + 7;
        
        int n = b.size();
        vector<bool> vis(n, false);
        vector<int> maxPower(n + 1, 0);
        
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                int curr = i;
                int len = 0;
                
                // Find cycle length
                while (!vis[curr]) {
                    vis[curr] = true;
                    curr = b[curr] - 1;
                    len++;
                }
                
                // Prime factorization of cycle length
                int num = len;
                
                for (int p = 2; p * p <= num; p++) {
                    int cnt = 0;
                    
                    while (num % p == 0) {
                        num /= p;
                        cnt++;
                    }
                    
                    maxPower[p] = max(maxPower[p], cnt);
                }
                
                if (num > 1) {
                    maxPower[num] = max(maxPower[num], 1);
                }
            }
        }
        
        long long ans = 1;
        
        // Calculate LCM modulo MOD
        for (int p = 2; p <= n; p++) {
            for (int j = 0; j < maxPower[p]; j++) {
                ans = (ans * p) % MOD;
            }
        }
        
        return ans;
    }
};