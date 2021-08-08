#include <bits/stdc++.h>
using namespace std;
#define ll                long long
#define v                 vector
#define st                set
#define ust               unorderd_set
#define m                 map
#define um                unorderd_map 
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
  // input
  int n; ll x; cin >> n >> x;
  v<ll> coins(n);
  for (ll &i: coins) cin >> i;
  
  sort(coins.begin(), coins.end());

  v<ll> dp(x+1, 0);
  // base case
  dp[0] = 1;


  for (ll c: coins) {
    loop (i, c, x) 
      dp[i] = (dp[i]%mod + dp[i-c]%mod)%mod;
  }

  cout << dp[x];

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
