#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define mid(l, h) ((l + h) / 2)
#define loop(i, a, b) for (int i = a; i <= b; ++i)
#define looprev(i, a, b) for (int i = a; i >= b; --i)
#define mod(a) (a % 100'000'007)
#define endl '\n'

void file_i_o() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
}

vi dp;

int ways(int n) {
  if (dp.size() <= n) dp.resize(n + 1, 0);

  if (dp[n]) return dp[n];

  if (not dp[n - 1]) dp[n - 1] = ways(n - 1);
  if (not dp[n - 2]) dp[n - 2] = ways(n - 2);

  dp[n] = dp[n - 1] + dp[n - 2];

  return dp[n];
}

void solve() {
  int n;
  cin >> n;
  cout << ways(n) << endl;
}

int32_t main() {
  clock_t start = clock();
  file_i_o();
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  dp.resize(3, 0);
  dp[0] = 1;
  dp[1] = 1;
  dp[2] = 2;
  int T;
  cin >> T;
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
