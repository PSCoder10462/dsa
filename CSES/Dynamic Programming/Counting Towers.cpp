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

v<v<ll>> dp(2, v<ll>(2, 0));

void solve() {
  int n; cin >> n;
  int last = (int)dp.size();
  if (n < last) {
    cout << (dp[n][0]+dp[n][1])%mod << endl; return;
  }
  dp.resize(n+1, v<ll>(2, 0));
  loop(i, last, n) {
    dp[i][0] = (((4*dp[i-1][0])%mod) + dp[i-1][1]%mod)%mod;
    dp[i][1] = (dp[i-1][0]%mod + ((2*dp[i-1][1])%mod))%mod;
  }
  cout << (dp[n][0]+dp[n][1])%mod << endl;
}

int main () {
  clock_t start = clock();
  file_i_o();
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll T;
  cin >> T;
  dp[1][0] = dp[1][1] = 1;
  while (T--) {
    solve();
  }
#ifndef ONLINE_JUDGE
clock_t end = clock();
cout << "\n\nExecuted in: " << (double)(end - start) / double(CLOCKS_PER_SEC)
<< " sec";
#endif
  return 0;
}
