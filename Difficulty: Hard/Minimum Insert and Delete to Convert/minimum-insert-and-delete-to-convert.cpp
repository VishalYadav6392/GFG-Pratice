class Solution {
  public:
    int minInsAndDel(vector<int> &a, vector<int> &b) {
        // code here
        unordered_set<int> st(b.begin(), b.end());

        vector<int> lis;

        for (int x : a) {
            if (!st.count(x)) continue;

            auto it = lower_bound(lis.begin(), lis.end(), x);

            if (it == lis.end())
                lis.push_back(x);
            else
                *it = x;
        }

        int L = lis.size();

        return (a.size() - L) + (b.size() - L);
    }
};