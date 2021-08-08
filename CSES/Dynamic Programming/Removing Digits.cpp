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

int getMaxDigit(ll n) {
  int ans=0;
  while (n) {
    int t = (int)(n%10);
    n /= 10;
    if (t > ans) ans = t; 
  } 
  return ans;
}

void solve() {
  ll n; cin >> n;
  v<ll> dp(n+1, -1);
  dp[0] = 0;
  loop(i, 1, n) {
    int d = getMaxDigit(i);
    if (d > i) continue;
    ll t = 1+dp[i-d];
    if (!t) continue;
    dp[i] = (dp[i] == -1) ? t : min(t, dp[i]);
  }
  cout << dp[n];
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
