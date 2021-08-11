/******************************************************/
#include <bits/stdc++.h>
using namespace std;
#define ll                long long
#define v                 vector
#define mp                make_pair
#define pb                push_back
#define mid(l, h)         ((l+h)/2)
#define loop(i, a, b)     for (auto i = a; i <= b; ++i)
#define looprev(i, a, b)  for (auto i = a; i >= b; --i)
#define mod               1'000'000'007
#define endl              '\n'
#define pinf              LLONG_MAX
#define ninf              LLONG_MIN
/******************************************************/

void file_i_o() {
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
}

void solve() {
  int n; cin >> n;
  v<int> arr(n);
  for (auto &i: arr) cin >> i;

  v<ll> dp;
  dp.pb(0);
  unordered_set<ll> s;
  loop(i, 0, n-1) {
    ll last = dp.size();
    loop(j, 0, last-1) {
      ll t = arr[i]+dp[j]; 
      if (s.find(t)!=s.end()) continue;
      dp.pb(t); s.insert(t);
    }
  }
  sort(dp.begin(), dp.end());
  cout << dp.size()-1 << endl;
  loop(i, 1, dp.size()-1) cout << dp[i] << ' ';
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
