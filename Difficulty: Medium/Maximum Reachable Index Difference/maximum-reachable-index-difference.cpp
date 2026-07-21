class Solution {
public:
    int maxIndexDifference(string &s) {
        int n = s.size();

        vector<int> best(26, -1);

        int ans = -1;

        for (int i = n - 1; i >= 0; i--) {
            int c = s[i] - 'a';

            int reach = i;

            if (c < 25 && best[c + 1] != -1)
                reach = best[c + 1];

            best[c] = max(best[c], reach);

            if (c == 0)
                ans = max(ans, reach - i);
        }

        return ans;
    }
};