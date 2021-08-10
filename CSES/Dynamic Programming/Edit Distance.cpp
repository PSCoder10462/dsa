#include <bits/stdc++.h>
using namespace std;
#define ll                long long
#define v                 vector
#define pb                push_back
#define mid(l, h)         ((l+h)/2)
#define loop(i, a, b)     for (auto i = a; i <= b; ++i)
#define looprev(i, a, b)  for (auto i = a; i >= b; --i)
#define mod               1'000'000'007
#define mp                make_pair
#define endl              '\n'
#define pinf              LLONG_MAX
#define ninf              LLONG_MIN

void file_i_o() {
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
}

void solve() {
  string s1, s2;  cin >> s1 >> s2;
  // s1 = love 
  // s2 = movie
  ll n = s1.length(), m = s2.length();


  v<v<ll>> dp(n+1, v<ll>(m+1, 0));
/*
      "" M O V I E
  ""  0
  L   1
  O   2
  V
  E
*/
  // column
  loop(i, 1, n) dp[i][0] = i;
  // row
  loop(i, 1, m) dp[0][i] = i;

  loop(i, 1, n) {
    loop(j, 1, m) {
      if (s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1];
      else {
        ll erase = dp[i-1][j],
           add   = dp[i][j-1],
           rep   = dp[i-1][j-1];
        dp[i][j] = 1 + min(min(erase, add), rep);
      }
    }
  }
  cout << dp[n][m];
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
