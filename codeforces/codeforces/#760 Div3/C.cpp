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
    int n; cin >> n;

    vi ve, vo;

    loop (i, 0, n) {
        ll t; cin >> t;
        if (i&1) {
            vo.pb(t);      
        } else {
            ve.pb(t);
        }
    }

    sort(all(vo));
    sort(all(ve));

    ll go = vo[0], ge = ve[0];

    for (auto i: vo) {
        go = __gcd(go, i);
        if (go == 1) break;
    }

    for (auto i: ve) {
        ge = __gcd(ge, i);
        if (ge == 1) break;
    }

    for (auto i: vo) {
        while (i%ge == 0 and ge != 1) {
            auto f = __gcd(i, ge);
            ge /= f;
        }
        if (ge == 1) break;
    }

    for (auto i: ve) {
        while (i%go == 0 and go != 1) {
            auto f = __gcd(i, go);
            go /= f;
        }
        if (go == 1) break;
    }

    ll ans = max(go, ge);

    cout << (ans == 1 ? 0 : ans) << endl;

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
