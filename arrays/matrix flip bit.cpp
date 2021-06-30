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

int f(vvi &mat, int n) {
  vi rz(n);
  vi cz(n);
  loop(i, 0, n - 1) {
    loop(j, 0, n - 1) {
      if (!mat[i][j]) {
        rz[i]++;
        cz[j]++;
      }
    }
  }
  int ans = 0;
  loop(i, 0, n - 1) {
    if (rz[i])
      ans += (n - rz[i]);
    else {
      loop(j, 0, n - 1) {
        if (cz[j]) ans++;
      }
    }
  }
  return ans;
}

void solve() {
  int n;
  cin >> n;
  vvi mat(n, vi(n, 0));
  loop(i, 0, n - 1) loop(j, 0, n - 1) cin >> mat[i][j];
  cout << f(mat, n) << endl;
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
