#define vb    vector<bool>
#define vvb   vector<vb>


int dfs(vector<vector<int>>& grid, vvb &vis, int n, int m, int r, int c) {
    if (r<0 or c<0 or r>=n or c>=m) return 0;
    
    if (!grid[r][c] or vis[r][c]) return 0;
    
    vis[r][c] = true;
    
    vector<int> dir = {-1, 0, 1};
    
    int size = 1;
    
    for (int i=0; i<=2; ++i) {
        for (int j=0; j<=2; ++j) {
            size += dfs(grid, vis, n, m, r+dir[i], c+dir[j]);
        }
    }
    
    return size;
    
}

int maxAreaOfIsland(vector<vector<int>>& grid, int n, int m) {
    // Write your code here.
    vvb vis(n, vb(m, false));
    
    int maxx = 0;
    
    for (int i=0; i<n; ++i) 
        for (int j=0; j<m; ++j) 
            if (grid[i][j] and !vis[i][j]) 
                maxx = max(dfs(grid, vis, n, m, i, j), maxx);
    
    return maxx;
    
}
