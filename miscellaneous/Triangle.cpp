class Solution {
public:
    const int INF = 1e9+5;
    
    void min_self(int &a, int b) {
        a = min(a, b);
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, INF));
        
        dp[0][0] = triangle[0][0];
        
        for (int i=0; i<n-1; ++i) {
            for (int j=0; j<=i; ++j) {
                min_self(dp[i+1][j], triangle[i+1][j] + dp[i][j]);
                min_self(dp[i+1][j+1], triangle[i+1][j+1] + dp[i][j]);
            }
        }
        
        int ans = INF;
        for (auto &i: dp[n-1])
            min_self(ans, i);
        return ans;
    }
};
