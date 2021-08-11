/******************************************************/
#include <bits/stdc++.h>
using namespace std;
#define ll                long long
#define v                 vector
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
  int a, b; cin >> a >> b;
  v<v<ll>> dp(a+1, v<ll>(b+1, 0));

  loop(i, 1, b) dp[1][i] = i-1; // base row
  loop(i, 1, a) dp[i][1] = i-1; // base column

  loop(i, 2, a) {
    loop(j, 2, b) {

      if (i == j) {
        dp[i][j] = 0; continue;
      }

      ll minCut_breadth = pinf, minCut_length = pinf;
      loop(k, 1, i-1) // cut breadth
        minCut_breadth = min(minCut_breadth, dp[k][j] + dp[i-k][j]);
      
      loop(k, 1, j-1) // cut lenght
        minCut_length = min(minCut_length, dp[i][k] + dp[i][j-k]);
    
      dp[i][j] = 1 + min(minCut_length, minCut_breadth);
    }
  }

  cout << dp[a][b];

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
