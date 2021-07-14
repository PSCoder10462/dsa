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

void solve() {
  int n, sum = 0;
  cin >> n;
  vi v(n);
  for (int &i : v) {
    cin >> i;
    sum += i;
  }
  if (n == 1) {
    cout << 1 << endl;
    return;
  }
  vi pre(n), suf(n);
  pre[0] = v[0];
  suf[n - 1] = v[n - 1];
  loop(i, 1, n - 1) pre[i] = __gcd(pre[i - 1], v[i]);
  looprev(i, n - 2, 0) suf[i] = __gcd(suf[i + 1], v[i]);
  int ans = sum / pre[n - 1];
  loop(i, 0, n - 1) {
    int k = __gcd((i - 1 < 0 ? 0 : pre[i - 1]), (i + 1 >= n ? 0 : suf[i+1]));
    ans = min(ans, 1 + ((sum - v[i]) / k));
  }
  cout << ans << endl;
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
