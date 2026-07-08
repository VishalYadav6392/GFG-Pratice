class Solution {
  public:
  
    void bfs(vector<vector<int>>& mat,
             queue<pair<int, int>>& q,
             vector<vector<bool>>& vis) {
        
        int n = mat.size();
        int m = mat[0].size();
        
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        
        while (!q.empty()) {
            
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for (int i = 0; i < 4; i++) {
                
                int nr = row + dr[i];
                int nc = col + dc[i];
                
                if (nr >= 0 && nr < n &&
                    nc >= 0 && nc < m &&
                    !vis[nr][nc] &&
                    mat[nr][nc] >= mat[row][col]) {
                    
                    vis[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
    }
    
    int countCoordinates(vector<vector<int>>& mat) {
        
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<bool>> P(n, vector<bool>(m, false));
        vector<vector<bool>> Q(n, vector<bool>(m, false));
        
        queue<pair<int, int>> qP;
        queue<pair<int, int>> qQ;
        
        // Top boundary -> Station P
        // Bottom boundary -> Station Q
        for (int j = 0; j < m; j++) {
            P[0][j] = true;
            qP.push({0, j});
            
            Q[n - 1][j] = true;
            qQ.push({n - 1, j});
        }
        
        // Left boundary -> Station P
        // Right boundary -> Station Q
        for (int i = 0; i < n; i++) {
            P[i][0] = true;
            qP.push({i, 0});
            
            Q[i][m - 1] = true;
            qQ.push({i, m - 1});
        }
        
        bfs(mat, qP, P);
        bfs(mat, qQ, Q);
        
        int ans = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                
                if (P[i][j] && Q[i][j]) {
                    ans++;
                }
            }
        }
        
        return ans;
    }
};