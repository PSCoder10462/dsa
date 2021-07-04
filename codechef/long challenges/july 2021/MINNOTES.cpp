// wrong answer !!!!

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define mid(l, h) (l + h / 2)
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
  cin >> n;
  vi v(n);
  loop(i, 0, n - 1) cin >> v[i];

  if (n == 1) {
    cout << 1 << endl;
    return;
  }

  vi pre(n), suf(n), exc(n);

  // calc pre and suf

  loop(i, 1, n - 2) {
    pre[i] = __gcd(pre[i - 1], v[i - 1]);
    suf[n - i - 1] = __gcd(suf[n - i], v[n - i]);
  }

  suf[0] = __gcd(suf[1], v[0]);
  pre[n - 1] = __gcd(pre[n - 2], v[n - 1]);
  exc[0] = suf[0];
  exc[n - 1] = pre[n - 1];
  loop(i, 1, n - 2) {}
  int maxx = 0, ind = 0;
  loop(i, 0, n - 1) {
    exc[i] = __gcd(suf[i], pre[i]);
    if (exc[i] > maxx) {
      ind = i;
      maxx = exc[i];
    } else if (exc[i] == maxx) {
      if (v[i] > v[ind]) {
        ind = i;
      }
    }
  }

  v[ind] = maxx;

  int ans = 0;
  loop(i, 0, n - 1) ans += v[i] / maxx;

  cout << ans << endl;

  // loop(i, 0, n - 1) cout << pre[i] << " ";
  // cout << endl;
  // loop(i, 0, n - 1) cout << suf[i] << " ";
  // cout << endl;
  // cout << "EXC : " << endl;
  // loop(i, 0, n - 1) cout << exc[i] << " ";
  // cout << endl << endl;
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
