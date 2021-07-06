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

int first(vi &v, int k, int l, int h) {
  if (l > h) return -1;
  int m = mid(l, h);
  if (v[m] == k) {
    if (m == 0 or v[m - 1] != k)
      return m;
    else
      return first(v, k, l, m - 1);
  }
  if (v[m] > k) return first(v, k, l, m - 1);

  return first(v, k, m + 1, h);
}

int last(vi &v, int k, int l, int h) {
  if (l > h) return -1;
  int m = mid(l, h);
  if (v[m] == k) {
    if (m == v.size() - 1 or v[m + 1] != k)
      return m;
    else
      return last(v, k, m + 1, h);
  }
  if (v[m] > k) return last(v, k, l, m - 1);
  return last(v, k, m + 1, h);
}

pair<int, int> solve() {
  int n, k;
  cin >> n >> k;
  vi v(n);
  loop(i, 0, n - 1) cin >> v[i];
  int f = first(v, k, 0, n - 1);
  if (f == -1) return pair<int, int>{-1, -1};
  int l = last(v, k, 0, n - 1);
  return pair<int, int>{f, l};
}

int32_t main() {
  clock_t start = clock();
  file_i_o();
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  cin >> T;
  while (T--) {
    pair<int, int> p = solve();
    cout << p.first << " " << p.second << endl;
  }
#ifndef ONLINE_JUDGE
  clock_t end = clock();
  cout << "\n\nExecuted in: " << (double)(end - start) / double(CLOCKS_PER_SEC)
       << " sec";
#endif
  return 0;
}
