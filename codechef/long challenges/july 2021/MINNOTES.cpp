// wrong answer !!!!

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
  cin >> n;
  vi v(n);
  loop(i, 0, n - 1) cin >> v[i];

  if (n == 1) {
    cout << 1 << endl;
    return;
  }

  vi pgcd(n), sgcd(n), egcd(n);

  loop(i, 1, n - 1) pgcd[i] = __gcd(pgcd[i - 1], v[i - 1]);

  looprev(i, n - 2, 0) sgcd[i] = __gcd(sgcd[i + 1], v[i + 1]);

  loop(i, 0, n - 1) egcd[i] = __gcd(sgcd[i], pgcd[i]);

  int sum = accumulate(v.begin(), v.end(), 0);

  int ans = LLONG_MAX;
  loop(i, 0, n - 1) {
    int temp = (sum - v[i] + egcd[i]) / egcd[i];
    if (ans > temp) ans = temp;
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
