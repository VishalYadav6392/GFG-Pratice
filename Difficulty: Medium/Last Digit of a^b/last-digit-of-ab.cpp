class Solution {
  public:
    int getLastDigit(string& a, string& b) {
        // code here
   if (b == "0")
            return 1;

        int base = a.back() - '0';
        int res = 1;

        for (char ch : b) {
            int digit = ch - '0';

            res = (modPow(res, 10) * modPow(base, digit)) % 10;
        }

        return res;
    }

    int modPow(int a, int b) {
        int res = 1;

        while (b) {
            if (b & 1)
                res = (res * a) % 10;

            a = (a * a) % 10;
            b >>= 1;
        }

        return res;
    }
};