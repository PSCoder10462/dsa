#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define mid(l, h) ((l+h)/2)
#define loop(i, a, b) for (int i = a; i <= b; ++i)
#define looprev(i, a, b) for (int i = a; i >= b; --i)
#define MOD 100'000'007
#define mp make_pair
#define endl '\n'
#define pii pair<int, int>

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
  for (int &i: v) cin >> i;
  pii ans = mp(1, 2);
  int minn = abs(v[1]-v[0]);
  loop (i, 2, n-1) {
    if (abs(v[i]-v[i-1]) < minn) {
      minn = abs(v[i]-v[i-1]);
      ans = mp(i, i+1);
    }
  }
  if (abs(v[n-1]-v[0]) < minn)
      ans = mp(n, 1);
    
  cout << ans.first << ' ' << ans.second;
}

int32_t main() {
  clock_t start = clock();
  file_i_o();
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
#ifndef ONLINE_JUDGE
  clock_t end = clock();
  cout << "\n\nExecuted in: " << (double)(end - start) / double(CLOCKS_PER_SEC)
       << " sec";
#endif
  return 0;
}
