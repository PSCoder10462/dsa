class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ctr = 0;
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                if (grid[i][j]) {
                    int c = 4;
                    if (i-1 >= 0 and grid[i-1][j]) c--;
                    if (i+1 < n and grid[i+1][j]) c--;
                    if (j-1 >= 0 and grid[i][j-1]) c--;
                    if (j+1 < m and grid[i][j+1]) c--;
                    ctr += c;
                }
            }
        }
        return ctr;
    }
};
