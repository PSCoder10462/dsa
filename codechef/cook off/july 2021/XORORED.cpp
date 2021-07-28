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
  int n;
  int x = 0, ans = 0;
  cin >> n;
  vi v(n);
  loop(i, 0, n - 1) cin >> v[i];
  loop(i, 0, 30) {
    int j = 1ll << i;
    int check = j & v[0];
    bool entered = false;
    bool one = check != 0;
    loop(num, 1, n - 1) {
      if (j & v[num]) one = true;
      if ((j & v[num]) != check) {
        ans += j;
        entered = true;
        break;
      }
    }
    if (not entered and one) {
      x += j;
    }
  }
  cout << x << ' ' << ans << endl;
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
