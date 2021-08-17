/******************************************************/
#include <bits/stdc++.h>
using namespace std;
#define ll                long long
#define vi                vector<ll>
#define vvi               vector<vi>
#define pii               pair<ll, ll>
#define pb                push_back
#define mp                make_pair
#define mid(l, h)         ((l+h)/2)
#define loop(i, a, b)     for (auto i = a; i <= b; ++i)
#define looprev(i, a, b)  for (auto i = a; i >= b; --i)
#define mod               1'000'000'007
#define endl              '\n'
#define ff                first
#define ss                second
#define pinf              LLONG_MAX
#define ninf              LLONG_MIN
/******************************************************/

void file_i_o() {
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
}

bool cmp(vi a, vi b) {
  return a[1] < b[1];
}

ll bs(vvi &p, ll i) {
  ll lo = 0, hi = i;
  while (lo <= hi) {
    ll m = mid(lo, hi);
    if (p[m][1] < p[i][0]) {
      // got the ans
      if (p[m+1][1] >= p[i][0]) return m;
      // not got the ans
      lo = m+1;
    } else hi = m-1;
  }
  return -1ll;
}

void solve() {
  ll n; cin >> n;
  vvi p(n, vi(3));
  for (auto &i: p) 
    for (auto &j: i) 
      cin >> j;

  sort(p.begin(), p.end(), cmp);

  ll dp[n];
  dp[0] = p[0][2]; // base case

  loop(i, 1, n-1) {
    ll excl = dp[i-1];
    ll incl = p[i][2];
    ll ind = bs(p, i);
    incl += (ind != -1) ? dp[ind] : 0;
    dp[i] = max(incl, excl);
  }
  cout << dp[n-1];
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
