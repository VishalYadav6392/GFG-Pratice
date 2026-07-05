class Solution {
  public:
    int maxCharGap(string &s) {
        // code here
        vector<int> first(26, -1);
        int ans = -1;

        for (int i = 0; i < s.size(); i++) {
            int ch = s[i] - 'a';

            if (first[ch] == -1) {
                first[ch] = i;
            } else {
                ans = max(ans, i - first[ch] - 1);
            }
        }

        return ans;
    }
};