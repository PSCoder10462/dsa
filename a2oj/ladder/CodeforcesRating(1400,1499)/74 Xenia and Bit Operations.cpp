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
    ll n, m; cin >> n >> m;
    vvi v(n+1);
    loop(i, 0, (1ll<<n)) {
        ll p; cin >> p;
        v[0].pb(p);
        if (i&1) {
            bool OR = true;
            ll ind = i;
            ll lvl = 0;
            while (ind&1) {
                ll val = (OR ? (v[lvl][ind] | v[lvl][ind-1]) 
                    : 
                    (v[lvl][ind] ^ v[lvl][ind-1]));
                // cout << val << endl;
                OR = !OR;
                v[lvl+1].pb(val);
                ind >>= 1ll;
                lvl++;
            }
        }
    }
    while (m--) {
        ll p, b;
        cin >> p >> b; 
        p--;
        v[0][p] = b;
        bool OR = true;
        ll ind = p;
        loop(lvl, 0, n) {
            if ((ind&1)==0) ind++;
            ll val = (OR ? (v[lvl][ind] | v[lvl][ind-1]) 
                    : 
                    (v[lvl][ind] ^ v[lvl][ind-1]));
            ind >>= 1ll;
            v[lvl+1][ind] = val;
            OR = !OR;    
        }
        cout << v[n][0] << endl;
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
