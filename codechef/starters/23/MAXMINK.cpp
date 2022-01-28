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

void max_self(int &a, int b) {
    a = max(a, b);
}

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n), b(n);
    for (auto &i: a) cin >> i;
    for (auto &i: b) cin >> i;
    vector<vector<int>> dp(k+1, vector<int>(1601, -1));
    dp[0][0] = 0;
    // dp[i][j] -> max possible sum of array b when i elements are chosen when 
    // sum of array a is j

    loop(i, 0, n) { // consider all n elements
        looprev(j, k-1, 0) { // num of elements chosen out of i
            loop(s, 0, 1601) { // possible sum 
                if (dp[j][s] != -1) { // if s is a possible sum
                    max_self(dp[j+1][s+a[i]], dp[j][s] + b[i]);
                }
            }
        }
    }

    int ans = 0;
    loop(i, 0, k+1) {
        loop(j, 0, 1601) {
            max_self(ans, min(dp[i][j], j));
        }
    }

    cout << ans << endl;

}

int main () {
    clock_t start = clock();
    file_i_o();
    ll T;
    cin >> T;
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
