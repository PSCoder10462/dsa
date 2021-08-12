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
  ll sum = n*(n+1)/2;
  if (sum&1) {
    cout << 0; return;
  }
  sum /= 2;
  vi dp(sum+1, 0);
  
  loop(i, 1, n) {
    looprev(j, sum, i+1) {
      dp[j] = (dp[j]%(2*mod) + dp[j-i]%(2*mod))%(2*mod);
    }
    dp[i]++;
    dp[i] %= (2*mod);
  }
  cout << (dp[sum]/2)%mod;
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
