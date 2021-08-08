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

v<int> getDigits(ll n) {
  v<int> ans;
  unordered_set<int> s;
  while (n) {
    int t = (int)(n%10);
    n /= 10;
    if (s.find(t) != s.end()) continue;
    ans.pb(t); s.insert(t); 
  } 
  return ans;
}

void solve() {
  ll n; cin >> n;
  v<ll> dp(n+1, -1);
  dp[0] = 0;
  loop(i, 1, n) {
    v<int> d = getDigits(i);
    for (int j: d) {
      if (j > i) continue;
      ll t = 1+dp[i-j];
      if (!t) continue;
      dp[i] = (dp[i] == -1) ? t : min(t, dp[i]);
    }
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
