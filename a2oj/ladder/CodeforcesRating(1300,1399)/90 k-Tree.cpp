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
    int n, k, d;
    cin >> n >> k >> d;
    vector<pii> dp(105, {0, 0});
    // dp[i] = true, false paths to reach weight i
    dp[0] = mp(0, 1);
    loop(i, 0, n+1) {
        loop(j, 1, k+1) {
            if (i+j > n) break;
            dp[i+j].ff += dp[i].ff;
            if (j >= d) {
                dp[i+j].ff += dp[i].ss;
            } else {
                dp[i+j].ss += dp[i].ss;
            }
            dp[i+j].ff %= mod;
            dp[i+j].ss %= mod;
        }
    }
    cout << dp[n].ff;
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
