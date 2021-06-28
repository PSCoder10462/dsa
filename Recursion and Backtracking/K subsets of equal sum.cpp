#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define vb vector<bool>
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

bool f(vi &v, vi &sss, bitset<1000> &taken, int rs, int k, int n, int idx,
       int lidx) {
  if (sss[idx] == rs) {
    if (idx == k - 2) return true;
    return f(v, sss, taken, rs, k, n, idx + 1, n - 1);
  }
  looprev(i, lidx, 0) {
    if (taken[i]) continue;
    int t = sss[idx] + v[i];
    if (t <= rs) {
      taken[i] = true;
      sss[idx] += v[i];
      bool nxt = f(v, sss, taken, rs, k, n, idx, i - 1);
      taken[i] = false;
      sss[idx] -= v[i];
      if (nxt) return true;
    }
  }
  return false;
}

bool splitArray(vi &arr, int K) {
  int n = arr.size();
  if (K == 1) return true;
  if (n < K) return false;
  int sum = 0;
  for (int i : arr) sum += i;
  if (sum % K) return false;
  bitset<1000> taken(false);
  vi sss(K, 0);
  sss[0] = arr[n - 1];
  taken[n - 1] = true;
  return f(arr, sss, taken, sum / K, K, n, 0, n - 1);
}

void solve() {
  int n, k;
  cin >> n >> k;
  vi v(n);
  loop(i, 0, n - 1) cin >> v[i];
  cout << splitArray(v, k);
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
