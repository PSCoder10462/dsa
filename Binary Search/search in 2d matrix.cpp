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

int findRow(vvi &v, int k, int l, int h) {
  if (l > h) return -1;

  int m = mid(l, h);

  if (m == h) return m;

  if (v[m][0] == k or (v[m][0] < k and v[m + 1][0] > k)) return m;

  if (v[m][0] > k) return findRow(v, k, l, m - 1);

  return findRow(v, k, m + 1, h);
}

void solve() {
  int n, m, k;
  cin >> k >> n >> m;

  vvi v(n, vi(m));

  loop(i, 0, n - 1) loop(j, 0, m - 1) cin >> v[i][j];

  int r = findRow(v, k, 0, n - 1);

  if (r == -1) {
    cout << "no\n";
    return;
  }

  int pc = lower_bound(v[r].begin(), v[r].end(), k) - v[r].begin();

  if (pc >= m or pc < 0) {
    cout << "no\n";
    return;
  }

  v[r][pc] == k ? cout << "yes\n" : cout << "no\n";
}

int32_t main() {
  clock_t start = clock();
  file_i_o();
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
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
