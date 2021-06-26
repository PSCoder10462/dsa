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

int ans = 0;

void f(vi &arr, int n, int sum1, int pos, int size, int sum2) {
  // base case
  // divided successfully
  if (size == n / 2) {
    ans = min(ans, abs(sum1 - sum2));
    return;
  }

  // can't divide
  if (((n - pos + 1) < (n / 2 - size)) or pos == n) {
    return;
  }

  // don't include
  f(arr, n, sum1, pos + 1, size, sum2);

  // include current element
  f(arr, n, sum1 - arr[pos], pos + 1, size + 1, sum2 + arr[pos]);
}

int tugOfWar(vi arr, int n) {
  int sum = 0;
  ans = (int)(1e5);
  for (int i : arr) sum += i;
  f(arr, n, sum, 0, 0, 0);
  return ans;
}

void solve() {
  int n;
  cin >> n;
  vi arr(n);
  loop(i, 0, n - 1) cin >> arr[i];
  cout << tugOfWar(arr, n) << endl;
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
