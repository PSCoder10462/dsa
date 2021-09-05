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
    ll n; cin >> n; 
    vi h(n); 
    for (auto &i: h) cin >> i;

    vi dp(n+1, 0);
    
    loop(i, 2, n) {
        dp[i] = dp[i-1] + abs(h[i-2]-h[i-1]);
        if (i > 2) 
            dp[i] = min(dp[i], dp[i-2] + abs(h[i-1] - h[i-3]));
    }

    cout << dp[n];
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
