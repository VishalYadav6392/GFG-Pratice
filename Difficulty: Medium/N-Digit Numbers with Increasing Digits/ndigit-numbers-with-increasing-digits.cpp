class Solution {
public:
    vector<int> ans;

    void solve(int num, int lastDigit, int len, int n) {
        if (len == n) {
            ans.push_back(num);
            return;
        }

        for (int d = lastDigit + 1; d <= 9; d++) {
            solve(num * 10 + d, d, len + 1, n);
        }
    }

    vector<int> increasingNumbers(int n) {
        ans.clear();

        if (n == 1) {
            for (int i = 0; i <= 9; i++)
                ans.push_back(i);
            return ans;
        }

        for (int first = 1; first <= 9; first++) {
            solve(first, first, 1, n);
        }

        return ans;
    }
};