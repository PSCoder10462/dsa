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
    string a, b;
    cin >> a >> b;
    ll n = (ll)a.length(), m = (ll)b.length();
    vvi dp(n+1, vi(m+1, 0));

    loop(i, 1, n) {
        loop(j, 1, m) {
            if (a[i-1] == b[j-1]) {
                dp[i][j] = max(dp[i-1][j-1]+1, max(dp[i][j-1], dp[i-1][j]));
            } else {
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }

    ll ctr = dp[n][m];
    string ans;
    looprev(i, n, 1) {
        looprev(j, m, 1) {
            if (dp[i][j] == ctr and a[i-1] == b[j-1]) {
                ans.pb(a[i-1]);
                
                if (j!=1) i--;
                ctr--;
                if (ctr == 0) {
                    looprev(z, dp[n][m]-1, 0) cout << ans[z];
                    return;
                }
            }
        }
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
