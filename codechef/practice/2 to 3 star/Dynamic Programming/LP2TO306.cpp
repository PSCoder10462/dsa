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
    ll n, k, p; cin >> n >> k >> p;
    vi v(n);
    vector<pii> sorted_v(n);
    loop(i, 0, n) {
        cin >> v[i];
        sorted_v[i].ff = v[i];
        sorted_v[i].ss = i;
    }
    sort(all(sorted_v));
    vi dpf(n), dpb(n);
    dpb[0] = sorted_v[0].ff - k;
    loop(i, 1, n) {
        if (sorted_v[i].ff-sorted_v[i-1].ff <= k) {
            dpb[i] = dpb[i-1]; 
        } else {
            dpb[i] = sorted_v[i].ff - k;
        }
    }
    dpf[n-1] = sorted_v[n-1].ff + k;
    looprev(i, n-2, 0) {
        if (sorted_v[i+1].ff-sorted_v[i].ff <= k) {
            dpf[i] = dpf[i+1]; 
        } else {
            dpf[i] = sorted_v[i].ff + k;
        }
    }
    vector<pii> final_dp(n);
    loop (i, 0, n) {
        ll ind = sorted_v[i].ss;
        final_dp[ind] = mp(dpb[i], dpf[i]);
    }
    while (p--) {
        ll a, b; cin >> a >> b;
        --a; --b;
        if (v[a] > v[b])
            swap(a, b);
        if (final_dp[a].ss >= v[b]) {
            cout << "Yes";
        } else cout << "No";
        cout << endl;
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
