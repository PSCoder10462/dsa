#include <bits/stdc++.h>
using namespace std;
#define int               long long
#define vi                vector<int>
#define vvi               vector<vi>
#define vb                vector<bool>
#define mid(l, h)         ((l+h)/2)
#define loop(i, a, b)     for (int i = a; i <= b; ++i)
#define looprev(i, a, b)  for (int i = a; i >= b; --i)
#define MOD               1'000'000'007
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

int diceCombinations(int n, vi &dp) {
  if (n < 0) return 0;
  if (dp[n]) return dp[n]%MOD;
  for (int i=1; i <= min(n, 6ll); ++i) {
    dp[n] += diceCombinations(n-i, dp)%MOD;
    dp[n] %= MOD;
  }
  return dp[n]%MOD;
}

void solve() {
  int n; cin >> n;
  vi dp(n+1);
  dp[0] = dp[1] = 1;
  cout << diceCombinations(n, dp);
}

int32_t main() {
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
