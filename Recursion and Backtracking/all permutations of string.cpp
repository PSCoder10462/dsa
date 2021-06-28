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

void f(string &s, int p, string osf, int n) {
  if (osf.length() == n) {
    cout << osf << endl;
    return;
  }

  loop(i, 0, osf.length()) {
    string temp;
    temp.push_back(s[p]);
    f(s, p + 1, osf.substr(0, i) + temp + osf.substr(i), n);
  }
}

void solve() {
  string s;
  cin >> s;
  int n = s.length();
  f(s, 0, "", n);
}

int main() {
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
