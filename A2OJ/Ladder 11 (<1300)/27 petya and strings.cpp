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

void file_i_o() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
}

void solve() {
  string s, t;
  cin >> s >> t;
  transform(s.begin(), s.end(), s.begin(), ::tolower);
  transform(t.begin(), t.end(), t.begin(), ::tolower);
  int n = s.length();
  loop(i, 0, n-1) {
    if (t[i]>s[i]) {
      cout << -1; return;
    } else if (t[i]<s[i]) {
      cout << 1; return;
    }
  }
  cout << 0;
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
