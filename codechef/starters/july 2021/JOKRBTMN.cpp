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
  int n, m, l;
  cin >> n >> m >> l;
  unordered_map<int, int> mp;
  loop(i, 1, m) {
    int k;
    cin >> k;
    loop(j, 0, k - 1) {
      int t;
      cin >> t;
      mp[t] = i;
    }
  }
  vi s(l);
  loop(i, 0, l - 1) cin >> s[i];

  int ctr = 1;

  int i = 1;
  while (i < l) {
    if (mp[s[i]] != mp[s[i - 1]]) ctr++;
    i++;
  }
  cout << ctr << endl;
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
