#include <bits/stdc++.h>
using namespace std;
#define ll                long long
#define v                 vector
#define pb                push_back
#define mid(l, h)         ((l+h)/2)
#define loop(i, a, b)     for (auto i = a; i <= b; ++i)
#define looprev(i, a, b)  for (auto i = a; i >= b; --i)
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
  ll n; int m; cin >> n >> m;
  v<int> arr(n+1);
  loop(i, 1, n) cin >> arr[i];

  v<v<ll>> dp (m+1, v<ll>(n+1, 0));

  // marking first column
  if (arr[1] != 0) dp[arr[1]][1] = 1; // fixed digit
  if (arr[1] == 0) loop(i, 1, m) dp[i][1] = 1; // unknown digit

  loop (i, 2, n) {
    if (arr[i] != 0) {
      int l = max(1, arr[i]-1),
          r = min(m, arr[i]+1);
      loop(j, l, r) 
        dp[arr[i]][i] = (dp[arr[i]][i]%mod + dp[j][i-1]%mod)%mod;
    } else {
      loop(j, 1, m) {
        int l = max(1, j-1),
            r = min(m, j+1);
        loop(k, l, r)
          dp[j][i] = (dp[j][i]%mod + dp[k][i-1]%mod)%mod;
      }
    }
  }

  ll ans = 0;
  loop (i, 1, m) ans += dp[i][n]%mod;

  cout << ans%mod;
  
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
