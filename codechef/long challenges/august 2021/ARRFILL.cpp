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

void solve() {
  ll n, m; cin >> n >> m;
  vector<pii> op(m);
  for (auto &[a, b]: op) cin >> a >> b;
  sort(op.rbegin(), op.rend());
  ll li = 1, sum = 0, rem = n;
  for (auto [x, y]: op) {
    li = lcm(li, y);
    ll left = n/li;
    sum += (rem-left)*x;
    rem = left;
    if (not rem) break;
  }
  cout << sum << endl;
}

int main () {
  clock_t start = clock();
  file_i_o();
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll T; cin >> T;
  while (T--)
    solve();
#ifndef ONLINE_JUDGE
clock_t end = clock();
cout << "\n\nExecuted in: " << (double)(end - start) / double(CLOCKS_PER_SEC)
<< " sec";
#endif
  return 0;
}
