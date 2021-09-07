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
    ll n; cin >> n;
    // activity -> column, day -> row
    vvi activities(n, vi (3, 0));
    
    loop(i, 0, n-1)
        loop(j, 0, 2) 
            cin >> activities[i][j];


    vvi dp(n, vi (3, -1));

    dp[0] = activities[0];

    loop(i, 1, n-1) {
        loop(j, 0, 2) {
            loop(k, 0, 2) {
                if (k == j) continue;
                dp[i][j] = max(dp[i][j], activities[i][j] + dp[i-1][k]);
            }
        }
    }

    ll ans = -1;
    loop(i, 0, 2)
        ans = max(ans, dp[n-1][i]);
    cout << ans;
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
