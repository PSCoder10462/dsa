#include <bits/stdc++.h>
using namespace std;
#define ll                long long
#define v                 vector
#define pb                push_back
#define mid(l, h)         ((l+h)/2)
#define loop(i, a, b)     for (ll i = a; i <= b; ++i)
#define looprev(i, a, b)  for (ll i = a; i >= b; --i)
#define mod               1'000'000'007
#define mp                make_pair
#define endl              '\n'
#define pinf              LLONG_MAX
#define ninf              LLONG_MIN

void file_i_o() {
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
}

void solve() {
  int n; cin >> n;
  v<v<bool>> matrix(n, v<bool>(n));
  loop(i, 0, n-1) loop(j, 0, n-1) {
    char c; cin >> c;
    matrix[i][j] = (c == '.');
  }
  
  if (not matrix[0][0] or not matrix[n-1][n-1]) {
    cout << 0; return;
  }

  v<v<ll>> dp(n, v<ll>(n, 0));

  dp[n-1][n-1] = 1;
  looprev (i, n-1, 0) {
    looprev (j, n-1, 0) {
      if (!matrix[i][j] or (i == n-1 and j==n-1)) continue;
      ll a1 = 0, a2 = 0;
      if (i < n-1) a1 = dp[i+1][j];
      if (j < n-1) a2 = dp[i][j+1];
      dp[i][j] =  (a1+a2)%mod;
    }
  }
  cout << dp[0][0];
}

int main () {
  clock_t start = clock();
  file_i_o();
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
#ifndef ONLINE_JUDGE
clock_t end = clock();
cout << "\n\nExecuted in: " << (double)(end - start) / double(CLOCKS_PER_SEC)
<< " sec";
#endif
  return 0;
}
