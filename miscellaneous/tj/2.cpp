******************************************************/
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
    ll n, m;
    cin >> n >> m;
    
    vvi v(n, vi(m));

    loop(i, 0, n-1)
        loop(j, 0, m-1)
            cin >> v[i][j];

    ll ans = 0;

    // up downs
    loop(i, 0, m-1) { // column
        ll u, d; u = d = 0;
        bool ui = false;
        loop(j, 0, n-1) { // row
            if (v[j][i] == 0) {
                d++;
                if (ui) u++;
            } else {
                ui = true;
                ans += (d+u);
                d = u = 0;
            }
        }
        ans += u;
    } 

    // left right
    loop(i, 0, n-1) { // column
        ll l, r; l = r = 0;
        bool li = false;
        loop(j, 0, m-1) { // row
            if (v[i][j] == 0) {
                r++;
                if (li) l++;
            } else {
                li = true;
                ans += (l+r);
                r = l = 0;
            }
        }
        ans += l;
        l = r = 0;
    } 

    cout << ans;

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
