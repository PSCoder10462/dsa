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
    ll n, m; cin >> n >> m;
    vi f(n), c(m);
    for (auto &i: f) cin >> i;
    for (auto &i: c) cin >> i;

    // sort(f.begin(), f.end());
    // sort(c.begin(), c.end());

    bool nwf = true;

    ll i, j; i = j = 0;

    ll cnt = 0;

    while (i < n and j < m) {
        while (i < n and j < m and c[j] > f[i]) i++;
        if (nwf and j<m and i < n) {cnt++; nwf = false; j++;}
        while (i < n and j < m and c[j] < f[i]) j++;
        if (!nwf and j < m and i < n) {cnt++; nwf = true; i++;}
    }

    if (nwf and j < m) cnt++;
    if (!nwf and i < n) cnt++;

    cout << cnt << endl;
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
