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
#define mp make_pair

void file_i_o() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
}

class cmpr {
 public:
  bool operator()(const pair<int, int> &c1, const pair<int, int> &c2) {
    return c2.second == c1.second ? c1.first < c2.first : c1.second > c2.second;
  }
};

void solve() {
  int n, d;
  cin >> n >> d;
  vector<pair<int, int>> v(n);
  loop(i, 0, n - 1) cin >> v[i].first;   // price
  loop(i, 0, n - 1) cin >> v[i].second;  // sweetness
  sort(v.begin(), v.end());              // sort first on price, then sweetness
  multiset<pair<int, int>, cmpr> mset;
  int ans = 0;
  int l = 0;  // from left
  // start from right
  looprev(r, n - 1, 0) {
    while (l < r and v[l].first + v[r].first <= d) mset.insert(v[l++]);
    auto it = mset.find(v[r]);
    // erasing occurance of right candy
    // else we buy same candy ie not allowed
    if (l > r and mset.end() != it) mset.erase(it);
    auto p1 = mset.empty() ? mp(0ll, 0ll) : *mset.begin();
    auto c1 = p1.first, s1 = p1.second;
    auto c2 = v[r].first, s2 = v[r].second;
    if (c1 + c2 <= d) ans = max(ans, s1 + s2);
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
