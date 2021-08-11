/******************************************************/
#include <bits/stdc++.h>
using namespace std;
#define ll                long long
#define vi                vector<ll>
#define vvi               vector<vi>
#define mp                make_pair
#define pb                push_back
#define mid(l, h)         ((l+h)/2)
#define loop(i, a, b)     for (auto i = a; i <= b; ++i)
#define looprev(i, a, b)  for (auto i = a; i >= b; --i)
#define mod               1'000'000'007
#define endl              '\n'
#define pinf              LLONG_MAX
#define ninf              LLONG_MIN
/******************************************************/

void file_i_o() {
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
}

void solve() {
  int n; cin >> n;
  vi arr(n);
  for (auto &a: arr) cin >> a;

  vvi dp(n, vi(n, 0));
  loop(len, 1, n) {
    loop(i, 0, n-len) {
      int j = i+len-1;
      ll x, y, z;
      x = (i+2 <= j)?dp[i+2][j]:0;
      y = (i+1 <= j-1)?dp[i+1][j-1]:0;
      z = (i <= j-2)?dp[i][j-2]:0;
      
      dp[i][j] = max(arr[i]+min(x, y), arr[j]+min(y, z));
    }
  }
  cout << dp[0][n-1];
}

int main () {
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
