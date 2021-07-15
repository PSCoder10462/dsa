// wa!!!!!!!!!!!!!!!!!

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

int mx = 100'005;
vi chefora(1), pre(mx);

int power(int x, int y) {
  int res = 1;
  x = mod(x);
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = mod(res * x);
    y = y >> 1;
    x = mod(x * x);
  }
  return res;
}

void solve() {
  int l, r;
  cin >> l >> r;
  cout << power(chefora[l], pre[r] - pre[l]) << endl;
}

int32_t main() {
  clock_t start = clock();
  file_i_o();
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  // precompute chefora numbers
  loop(i, 1, mx - 1) {
    int res, num;
    res = num = i;
    num /= 10;
    while (num) {
      res = res * 10 + num % 10;
      num /= 10;
    }
    chefora.push_back(res);
  }

  int n = chefora.size();
  loop(i, 1, n - 1) pre[i] = pre[i - 1] + chefora[i];

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
