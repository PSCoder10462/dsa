#include <bits/stdc++.h>
using namespace std;
#define ll                long long
#define vl                vector<ll>
#define vvl               vector<vl>
#define vb                vector<bool>
#define mid(l, h)         ((l+h)/2)
#define loop(i, a, b)     for (ll i = a; i <= b; ++i)
#define looprev(i, a, b)  for (ll i = a; i >= b; --i)
#define mod               1'000'000'007
#define mp                make_pair
#define endl              '\n'
#define pinf              LLONG_MAX
#define ninf              LLONG_MIN

void file_i_o() {
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
}

void solve() {
  int f, s;
  f = s = 0;
  loop(i, 1, 3) {
    int n; cin >> n;
    f += n;
  }
  loop(i, 1, 3) {
    int n; cin >> n;
    s += n;
  }
  int ans = s > f;
  cout << ans + 1 << endl;
}

int main () {
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
