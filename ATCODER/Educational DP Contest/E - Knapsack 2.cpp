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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

void solve() {
    ll n, w; cin >> n >> w;
    vector<pii> p(n);

    ll max_val = 0;

    loop(i, 0, n-1) {
        cin >> p[i].ff >> p[i].ss;
        max_val += p[i].ss;
    }
    
    sort(p.begin(), p.end());

    vvi dp (n+1, vi (max_val+1, -1));

    loop(i, 0, n) dp[i][0] = 0;

    loop(i, 1, n) {
        loop(j, 1, max_val) {

            if (dp[i-1][j] != -1) dp[i][j] = dp[i-1][j];

            // can't buy
            if (j < p[i-1].ss) continue;

            // can buy
            ll left_val = j - p[i-1].ss;

            if (dp[i-1][left_val] == -1) continue;

            if (dp[i][j] == -1) {
                dp[i][j] = p[i-1].ff + dp[i-1][left_val];
            } else {
                dp[i][j] = min(dp[i][j], p[i-1].ff + dp[i-1][left_val]);
            }
        }
    }

    looprev(i, max_val, 0) 
        if (dp[n][i] != -1 and dp[n][i] <= w) {
            cout << i; return;
        }
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
