/******************************************************/
#include <bits/stdc++.h>
using namespace std;
#define int               long long
#define vi                vector<int>
#define vvi               vector<vi>
#define all(v)            v.begin(), v.end()
#define pii               pair<int, int>
#define pb                push_back
#define sz(container)     (container.size()) 
#define mid(l, h)         (l+(h-l)/2)
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

void dfs(vvi &graph, vector<bool> &vis, int src) {
    vis[src] = true;
    for (auto i: graph[src]) {
        if (!vis[i]) {
            vis[i] = true;
            dfs(graph, vis, i);
        }
    }
}

int get_team(int n) {
    return (n == 1 ? 2 : 1);
}

bool dfs(vvi &graph, vi &ans, int src) {
    int team = get_team(ans[src]);
    bool flag = true;
    for (auto i: graph[src]) {
        if (ans[src] == ans[i]) return false;
        if (!ans[i]) {
            ans[i] = team;
            flag = flag and dfs(graph, ans, i);
        }
    }
    return flag;
}

void solve() {
    int n, m; cin >> n >> m;
    vvi graph(n+1);
    loop(i, 0, m) {
        int u, v; cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    
    vi ans(n+1, 0);

    loop(i, 1, n+1) {    
        if (!ans[i]) {
            ans[i] = 1;
            if (!dfs(graph, ans, i)) {
                cout << "IMPOSSIBLE";
                return;
            }
        }
    }   

    loop(i, 1, n+1) cout << ans[i] << ' ';
}

int32_t main () {
    clock_t start = clock();
    file_i_o();
    solve();
#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\nExecuted in: " << 
        (double)(end - start) / double(CLOCKS_PER_SEC)
        << " sec";
#endif
    return 0;
}
