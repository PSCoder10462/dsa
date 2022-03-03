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

void dfs(ll src, vvi &adj, vector<bool> &vis, ll val, vi &ans, set<ll>&d) {
    vis[src] = true;
    ans[src] = val;
    d.insert(src+1);
    d.insert(src-1);
    for (auto i: adj[src]) {
        if (!vis[i]) 
            dfs(i, adj, vis, val, ans, d);
    }
}

void solve() {
    ll n, m; cin >> n >> m;
    vvi adj(n+1);
    loop(_, 0, m) {
        ll u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    ll val = 0;
    vector<bool> vis(n+1, false);
    vi ans(n+1, -1);
    set<ll> d {n};
    vi v;
    while (ans[1] == -1) {
        for (auto i: d)
            if (i >= 1 and i <= n and !vis[i])
                v.pb(i);
        d.clear();
        for (auto i: v) {
            dfs(i, adj, vis, val, ans, d);
        }
        val++;
        v.clear();
    }
    cout << ans[1] << endl;
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
