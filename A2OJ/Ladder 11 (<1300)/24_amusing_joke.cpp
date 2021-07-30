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
  string host, guest, shuffled;
  cin >> host >> guest >> shuffled;
  vi a(26);
  for (char c: host) a[c-'A']++;
  for (char c: guest) a[c-'A']++;
  vi b(26);
  for (char c: shuffled) b[c-'A']++;
  loop(i, 0, 25) {
  	if (a[i] != b[i]) {
  		cout << "NO";
  		return;
  	}
  }
  cout << "YES";
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
