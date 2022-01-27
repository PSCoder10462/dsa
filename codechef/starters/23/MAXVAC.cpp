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
    ll n, x; cin >> n >> x;
    string s; cin >> s;
    vi v;
    ll st, en;
    st = 0;
    while (st < n) {
        en = st;
        while (en < n and s[en] == '0') ++en;
        v.pb(en-st);
        st = en;
        while (en < n and s[en] == '1') ++en;
        v.pb(en-st);
        st = en;
    }
    if (s[n-1] == '1') v.pb(0);
    // for (auto const &i: v) cout << i << ' ';
    // cout << endl;

    ll no_holiday = 0;

    for (ll i=0; i<(ll)v.size(); i += 2)
        no_holiday += v[i]/x;

    bool flag = false;
    for (ll i=1; i<(ll)v.size(); i += 2) {
        if (v[i] == 1) {
            ll check = (v[i-1] + v[i+1] + 1) / x;
            ll t = v[i-1]/x + v[i+1]/x;
            if (check > t) {
                flag = true;
                break;
            }
        } else {
            ll check1 = (v[i-1]+1) / x;
            ll check2 = (v[i+1]+1) / x;
            ll t1 = v[i-1]/x;
            ll t2 = v[i+1]/x;
            if (check1 > t1 or check2 > t2) {
                flag = true;
                break;
            }
        }
    }
    cout << (flag ? no_holiday + 1 : no_holiday) << endl;

}

int main () {
    clock_t start = clock();
    file_i_o();
    int tt; cin >> tt;
    while (tt--)
        solve();
#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\nExecuted in: " << (double)(end - start) / double(CLOCKS_PER_SEC)
    << " sec";
#endif
    return 0;
}
