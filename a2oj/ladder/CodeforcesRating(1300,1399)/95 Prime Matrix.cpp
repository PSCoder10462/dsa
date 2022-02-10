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

const int INF = 1e5+5;
vector<bool> is_prime(INF, true);
vector<int> sieve;

void init_sieve() {
    is_prime[0] = is_prime[1] = false;
    for (int i=2; i*i < INF; ++i) {
        if (!is_prime[i]) continue;
        for (int j=2; j*i < INF; ++j) {
            is_prime[i*j] = false;
        }
    }
    for (int i=2; i<INF; ++i)
        if (is_prime[i])
            sieve.pb(i);
}


void solve() {
    init_sieve();
    int n, m; cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m));
    loop(i, 0, n)
        loop(j, 0, m) {
            int t; cin >> t;
            int pos = lower_bound(all(sieve), t) - sieve.begin();
            mat[i][j] = sieve[pos] - t;
        }
    ll ans = pinf;

    // checking rows
    for (auto i: mat)
        ans = min(ans, accumulate(all(i), 0ll));

    // check col
    for (int i=0; i<m; ++i) {
        ll s = 0;
        for (int j=0; j<n; ++j)
            s += mat[j][i];
        ans = min(ans, s);
    }
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
