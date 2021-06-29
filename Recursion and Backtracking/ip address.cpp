#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(i, a, b) for (int i = a; i <= b; ++i)
#define looprev(i, a, b) for (int i = a; i >= b; --i)
#define mod(a) (a % 100'000'007)
#define vi vector<int>
#define vvi vector<vi>
#define endl '\n'

void file_i_o() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
}

void f(string &s, int nod, int n, int p, string osf) {
  if (n - p <= 3 - nod) return;

  if (nod == 3) {
    string t = s.substr(p);
    if ((t.length() > 1 and t[0] == '0') or (t.length() > 3) or (stoi(t) > 255))
      return;
    cout << "\"" << osf + t << "\"" << endl;
    return;
  }
  loop(i, 1, n - p) {
    string t = s.substr(p, i);
    if ((t.length() > 2 and t[0] == '0') or (t.length() > 3) or (stoi(t) > 255))
      return;
    f(s, nod + 1, n, p + i, osf + t + ".");
  }
}

void solve() {
  string s;
  cin >> s;
  f(s, 0, s.length(), 0, "");
}

int main() {
  clock_t start = clock();
  file_i_o();
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  std::cin >> T;
  while (T--) {
    solve();
    cout << endl;
  }
#ifndef ONLINE_JUDGE
  clock_t end = clock();
  cout << "\n\nExecuted in: " << (double)(end - start) / double(CLOCKS_PER_SEC)
       << " sec";
#endif
  return 0;
}
