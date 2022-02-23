/******************************************************/
#include <bits/stdc++.h>
using namespace std;
#define ll                long long
#define vi                vector<ll>
#define vvi               vector<vi>
#define all(v)            v.begin(), v.end()
#define pii               pair<ll, ll>
#define pb                push_back
#define mp                make_pair
#define mid(l, h)         ((l+h)/2)
#define loop(i, a, b)     for (auto i = a; i < b; ++i)
#define looprev(i, a, b)  for (auto i = a; i >= b; --i)
#define mod               1'000'000'007
#define endl              '\n'
#define ff                first
#define ss                second
#define pinf              LLONG_MAX
#define ninf              LLONG_MIN
/******************************************************/

void file_i_o() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

void solve() {
    int n; cin >> n;
    const ll INF = 1e9+5;
    vvi dp(8, vi(n+1, INF));
    // 0a 1b 2c
    loop(i, 1, n+1) {
        ll cost; cin >> cost;
        string s; cin >> s; 
        int str_msk = 0;
        loop(i, 0u, s.length()) {
            str_msk ^= (1 << (s[i]-'A'));
        }
        dp[str_msk][i] = min(dp[str_msk][i-1], cost);
        loop(mask, 0, 8) {
            dp[mask][i] = min(dp[mask][i-1], dp[mask][i]);
            dp[mask|str_msk][i] = min(dp[mask|str_msk][i], dp[mask][i] + cost);
        }
    }
    cout << (dp[7][n] == INF ? -1 : dp[7][n]);
}

int main () {
    clock_t start = clock();
    file_i_o();
    solve();
#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\nExecuted in: " << (double)(end - start) / double(CLOCKS_PER_SEC)
    << " sec";
#endif
    return 0;
}
