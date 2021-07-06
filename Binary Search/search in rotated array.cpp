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

int findk(vector<int> &v, int n, int k, int l, int h) {
  // base case: not found
  if (l > h or (l == h and v[l] != k)) return -1;

  int m = mid(l, h);

  // base case: found
  if (v[m] == k) return m;

  if (k == v[l]) return l;

  if (k > v[l]) {
    if (k > v[m])
      return findk(v, n, k, m + 1, h);
    else
      return findk(v, n, k, l, m - 1);
  }
  return findk(v, n, k, m + 1, h);
}

void solve() {
  int n, k;
  cin >> n >> k;
  vi v(n);
  loop(i, 0, n - 1) cin >> v[i];
  cout << findk(v, n, k, 0, n - 1) << endl;
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
