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
    vector<pair<int, string>> v;
    ll n, m; cin >> n >> m;
    loop(i, 0, n-1) {
        string s; cin >> s;
        ll ctr=0;
        loop(j, 0, m-1) ctr += (s[j]-'0');
        v.pb(mp(ctr, s));
    }
    sort(v.begin(), v.end());
    ll inv = 0, otl = 0;
    loop(i, 0, n-1) {
        loop(j, 0, m-1) {
            switch(v[i].ss[j]) {
                case '0':
                    inv += otl;
                    break;
                default: otl++;
            }
        }
    }
    cout << inv << endl;
}

int main () {
    clock_t start = clock();
    file_i_o();
    ll T; cin >> T;
    while (T--)
        solve();
#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\nExecuted in: " << (double)(end - start) / double(CLOCKS_PER_SEC)
    << " sec";
#endif
    return 0;
}
