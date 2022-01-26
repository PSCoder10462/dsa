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

void getF(string &s, vector<int> &f) {
    for (auto i: s)
        switch(i) {
            case 'B': f[0]++;
            break;
            case 'S': f[1]++;
            break;
            default: f[2]++;
        }
}

void solve() {
    string s; cin >> s;
    vector<int> f(3, 0);
    getF(s, f);
    vector<int> n(3), p(3);
    for (auto &i: n) cin >> i;
    for (auto &i: p) cin >> i;
    ll r; cin >> r;
    
    ll lo = -1, hi = 1e15+5;
    while (lo != hi-1) {
        ll m = mid(lo, hi);
        // can make m burgers ?
        ll temp = r;
        temp -= max((f[0]*m - n[0])*p[0], 0ll);
        temp -= max((f[1]*m - n[1])*p[1], 0ll);
        temp -= max((f[2]*m - n[2])*p[2], 0ll);
    
        // possible        
        if (temp >= 0)
            lo = m;
        // not possible
        else 
            hi = m; 
    }

    cout << lo;
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
