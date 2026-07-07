class Solution {
  public:
    int largestArea(int n, int m, vector<vector<int>> &arr) {
        
        vector<int> rows;
        vector<int> cols;
        
        // Store blocked rows and columns
        for (auto &x : arr) {
            rows.push_back(x[0]);
            cols.push_back(x[1]);
        }
        
        sort(rows.begin(), rows.end());
        sort(cols.begin(), cols.end());
        
        int maxRow = 0;
        int prev = 0;
        
        // Find maximum continuous free rows
        for (int row : rows) {
            maxRow = max(maxRow, row - prev - 1);
            prev = row;
        }
        
        // Rows after the last blocked row
        maxRow = max(maxRow, n - prev);
        
        
        int maxCol = 0;
        prev = 0;
        
        // Find maximum continuous free columns
        for (int col : cols) {
            maxCol = max(maxCol, col - prev - 1);
            prev = col;
        }
        
        // Columns after the last blocked column
        maxCol = max(maxCol, m - prev);
        
        return maxRow * maxCol;
    }
};