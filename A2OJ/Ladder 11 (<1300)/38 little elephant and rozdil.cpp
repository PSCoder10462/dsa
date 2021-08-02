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
#define umii unordered_map<int, int>

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
  int minn = LLONG_MAX;
  for (auto &i: v) {
    cin >> i;
    if (i < minn) minn = i;
  }
  int val = -1;
  loop (i, 0, n-1) {
    if (v[i] == minn and val != -1) {
      cout << "Still Rozdil"; return;
    }
    if (v[i] == minn) val = i;
  }
  cout << val+1;
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
