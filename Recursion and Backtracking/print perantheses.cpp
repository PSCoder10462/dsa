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

unordered_set<string> st;

void f(int ol, string osf, int n) {
  if (st.find(osf) != st.end()) return;
  st.insert(osf);
  if (ol == n) {
    cout << osf << endl;
    return;
  }

  looprev(i, ol, 0) {
    loop(j, i, 2 * ol) {
      string t =
          osf.substr(0, i) + "{" + osf.substr(i, j - i) + "}" + osf.substr(j);
      f(ol + 1, t, n);
    }
  }
}

void solve() {
  int n;
  cin >> n;
  f(1, "{}", n);
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
