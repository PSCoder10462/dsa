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

bool check(vi &v, int k, int m) {
  int cp = 1, cur = 0;
  int last = 0;
  for (int i = 1; i < v.size(); ++i) {
    cur = v[i] - v[last];
    if (cur >= m) {
      cur = 0;
      cp++;
      last = i;
      if (cp == k) return true;
    }
  }
  return false;
}

int f(vi &v, int k) {
  int n = v.size();
  sort(v.begin(), v.end());
  int lo = 0, hi = v[n - 1], ans = 0;
  while (hi >= lo) {
    int m = mid(hi, lo);
    if (check(v, k, m)) {
      ans = max(m, ans);
      lo = m + 1;
    } else
      hi = m - 1;
  }
  return ans;
}

void solve() {
  int n, k;
  cin >> n >> k;
  vi v(n);
  loop(i, 0, n - 1) cin >> v[i];
  cout << f(v, k) << endl;
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
