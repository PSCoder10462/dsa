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

const ll INF = 1e6+5;

vi number_of_factors(INF, 0);

vvi dp(5, vi (INF, 0));

void precompute() {
    for (ll i=2; i<INF; ++i) {
        if (number_of_factors[i] > 0) continue;
        for(ll j=2; j*i < INF; ++j) {
            // if (i == j) continue;
            number_of_factors[i*j]++;
        }
    }

    loop(i, 1, 6) {
        loop(j, 2, INF) {
            dp[i-1][j] = dp[i-1][j-1];
            if (number_of_factors[j] == i)
                dp[i-1][j]++;
            if (number_of_factors[j] == 0 and i == 1)
                dp[i-1][j]++;
        }
    }
    
    // loop(i, 2, INF)
    //     cout << i << ' ' << number_of_factors[i] << endl;
    
    // loop(i, 0, 5) {
    //     loop(j, 0, 25)
    //         cout << dp[i][j] << ' ';
    //     cout << endl;
    // }
}

void solve() {
    ll a, b, k; cin >> a >> b >> k;
    cout << dp[k-1][b] - dp[k-1][a-1] << endl;
}

int main () {
    clock_t start = clock();
    file_i_o();
    ll T;
    cin >> T;
    precompute();
    while (T--) {
      solve();
    }
#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\nExecuted in: " << (double)(end - start) / double(CLOCKS_PER_SEC)
    << " sec";
#endif
    return 0;
}
