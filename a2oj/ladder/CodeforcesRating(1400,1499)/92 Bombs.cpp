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

bool cmp(pii c, pii d) {
    pair <unsigned ll, unsigned ll> a, b;
    a = mp(llabs(c.ff), llabs(c.ss));
    b = mp(llabs(d.ff), llabs(d.ss));
    unsigned ll sqa = a.ff*a.ff + a.ss*a.ss;
    unsigned ll sqb = b.ff*b.ff + b.ss*b.ss;
    return sqa <= sqb;
}

void solve() {
    vector<pii> z, nz;
    ll n; cin >> n; 
    loop(i, 0, n) {
        ll a, b; cin >> a >> b;
        if (a && b) {
            nz.pb(mp(a, b));
        } else {
            z.pb(mp(a, b));
        }
    }
    sort(all(z), cmp);
    sort(all(nz), cmp);
    
    vvi ans;
    for (auto [x, y]: z) {
        vi t {1}, u {1};
        if (x) {
            t.pb(llabs(x));
            u.pb(llabs(x));
            if (x < 0) {
                t.pb('L');
                u.pb('R');
            } else {
                t.pb('R');
                u.pb('L');
            }
        } else {
            t.pb(llabs(y));
            u.pb(llabs(y));
            if (y < 0) {
                t.pb('D');
                u.pb('U');
            } else {
                t.pb('U');
                u.pb('D');
            }
        }
        ans.pb(t);
        ans.pb({2});
        ans.pb(u);
        ans.pb({3});
    }
    for (auto [x, y]: nz) {
        vi t {1}, u {1}, v {1}, w {1};
        
        t.pb(llabs(x));
        u.pb(llabs(x));
            if (x < 0) {
                t.pb('L');
                u.pb('R');
            } else {
                t.pb('R');
                u.pb('L');
            }
        v.pb(llabs(y));
        w.pb(llabs(y));
            if (y < 0) {
                v.pb('D');
                w.pb('U');
            } else {
                v.pb('U');
                w.pb('D');
            }
        ans.pb(t);
        ans.pb(v);
        ans.pb({2});
        ans.pb(w);
        ans.pb(u);
        ans.pb({3});
    }
    cout << ans.size() << endl;
    for(auto p: ans) {
        int ctr = 1;
        for(auto q: p) { 
            if (ctr == 3) {
                cout << char(q) << ' ';
            } else {
                cout << q << ' ';
            }
            ctr++;
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
