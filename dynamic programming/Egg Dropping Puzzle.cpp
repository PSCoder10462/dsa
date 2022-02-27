// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int eggDrop(int n, int k) 
    {
        const int INF = 1e9+5;
        vector<vector<int>> dp(n+1, vector<int> (k+1, INF));
        // base cases
        for (int i=0; i<=n; ++i)
            dp[i][0] = 0;
        for (int i=1; i<=k; ++i) 
            dp[1][i] = i;
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= k; ++j) {
                int maxx = INF;
                for (int l = 1; l <= j; ++l) {
                    int t = max(dp[i-1][l-1], dp[i][j-l]);
                    maxx = min(t, maxx);
                }
                if (maxx < INF)
                    dp[i][j] = 1 + maxx;
            }
        }
        return dp[n][k];
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}
  // } Driver Code Ends
