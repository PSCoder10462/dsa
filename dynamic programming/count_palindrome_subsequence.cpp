#define ll long long
const ll mod = 1000000007;
ll N = str.length();
vector<vector<ll>> dp(N, vector<ll>(N, 0));
for (ll i=0; i<N; ++i) 
  dp[i][i] = 1;
for (ll len = 1; len < N; ++len) {
 for (ll start = 0; start + len < N; ++start) {
     ll end = start + len;
     if (str[start] ==  str[end]) {
         dp[start][end] = 1 + dp[start + 1][end] + dp[start][end-1];
     } else {
         dp[start][end] = dp[start+1][end] + dp[start][end-1] - dp[start+1][end-1];
     }
    dp[start][end] %= mod;
 }
}
return dp[0][N-1];
