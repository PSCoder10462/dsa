#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define mid(l, h) (l + h / 2)
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

bool isSymmetric(vvi &matrix) {
  int n = matrix.size();
  loop(i, 0, n - 1)
      loop(j, 0, n - 1) if (matrix[i][j] != matrix[j][i]) return false;
  return true;
}

void solve() {
  int n;
  cin >> n;
  vvi matrix(n, vi(n));
  loop(i, 0, n - 1) loop(j, 0, n - 1) cin >> matrix[i][j];
  isSymmetric(matrix) ? cout << "yes" : cout << "no";
  cout << endl;
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
