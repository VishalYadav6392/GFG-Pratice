class Solution {
  public:
    int minDeletions(vector<int>& arr) {
        // code here
        vector<int> tails;

        for (int x : arr) {
            auto it = lower_bound(tails.begin(), tails.end(), x);
    
            if (it == tails.end()) {
                tails.push_back(x);   // extend LIS
            } else {
                *it = x;              // improve ending value
            }
        }

        return arr.size() - tails.size();
        
    }
};