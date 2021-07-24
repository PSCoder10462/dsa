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
  int n, q;
  cin >> n >> q;
  vi v(n);
  loop(i, 0, n - 1) cin >> v[i];
  vi odds(n + 1);
  loop(i, 1, n) {
    odds[i] = odds[i - 1];
    if (v[i - 1] % 2) odds[i]++;
  }
  loop(i, 1, q) {
    int l, r;
    cin >> l >> r;
    int oc = odds[r] - odds[l - 1];
    int ec = (r - l + 1) - oc;
    int ans = ec >= 3 ? (ec * (ec - 1) * (ec - 2)) / 6 : 0;
    ans += ((oc - 1) * oc * ec) / 2;
    cout << ans << endl;
  }
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
