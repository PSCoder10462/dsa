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
    ll n; cin >> n;
    vi v(n+1);
    loop(i, 1, n+1) cin >> v[i];
    vi pre(n+1, 0);
    loop(i, 1, n+1) pre[i] = pre[i-1]+v[i];
    sort(all(v));
    loop(i, 1, n+1) v[i] = v[i-1] + v[i];

    ll m; cin >> m;

    while (m--) {
        ll t, l, r;
        cin >> t >> l >> r;
        switch(t) {
            case 1:
                cout << pre[r]-pre[l-1];
                break;
            default:
                cout << v[r] - v[l-1];
        }
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
