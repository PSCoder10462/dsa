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

void dfs(auto &v, auto &vis, auto &src) {
    vis[src] = true;
    for (auto i: v[src]) {
        if (!vis[i]) {
            dfs(v, vis, i);
            vis[i] = true;
        }
    }
}

void solve() {
    int n; cin >> n;
    vector<vector<int>> v(n);
    vector<int> x(1001, -1), y(1001, -1);
    loop(i, 0, n) {
        int a, b; cin >> a >> b;
        if (x[a] != -1) {
            // point with x = a exists
            v[x[a]].pb(i);
            v[i].pb(x[a]);
        } else {
            x[a] = i;
        }
        if (y[b] != -1) {
            v[y[b]].pb(i);
            v[i].pb(y[b]);
        } else {
            y[b] = i;
        }
    }
    vector<bool> vis(n, false);
    int ctr = 0;
    loop(i, 0, n) {
        if (!vis[i]) {
            ctr++;
            dfs(v, vis, i);
        }
    }
    cout << ctr-1;
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
