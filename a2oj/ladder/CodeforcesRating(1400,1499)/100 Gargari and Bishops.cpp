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
    vvi b(n, vi (n, 0));
    for (auto &i: b) {
        for (auto &j: i) cin >> j;
    }
    vi f(2*n), s(2*n);
    loop(i, 0, n) {
        loop(j, 0, n) {
            s[i+j] += b[i][j];
            f[n+(i-j)] += b[i][j];
        }
    }
    ll ans[2];
    ans[0] = ans[1] = -1;
    pii pos[2];
    loop(i, 0, n) {
        loop(j, 0, n) {
            ll t = (s[i+j] + f[n + (i-j)] - b[i][j]);
            ll o = ((i+j)&1);
            if (ans[o] < t) {
                ans[o] = t;
                pos[o] = mp(i, j);
            }
        }
    }
    cout << ans[0] + ans[1] << endl;
    loop(i, 0, 2) 
        cout << pos[i].ff+1 << ' ' << pos[i].ss+1 << ' ' ;
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
