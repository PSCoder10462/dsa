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

const int INF = 2e5;
vi parent(INF);


void dfs(vvi &graph, vector<bool> &vis, int src, int p = -1) {
    parent[src] = p;
    vis[src] = true;
    for (auto i: graph[src]) {
        if (!(i^p)) continue;
        if (vis[i]) {
            // print cycle
            vi ans {i};
            while (i^src) {
                ans.pb(src);
                src = parent[src];                
            }
            ans.pb(i);
            cout << sz(ans) << endl;
            for (auto const &i: ans) cout << i << ' ';
            exit(0);
        } else {
            dfs(graph, vis, i, src);
        }
    }
}

void solve() {
    int n, m; cin >> n >> m;
    vvi graph(n+1);
    loop(i, 0, m) {
        int u, v; cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    vector<bool> vis(n+1, false);
    vi par(n+1);
    loop(i, 1, n+1) {
        if (!vis[i]) 
            dfs(graph, vis, i);
    }    
    cout << "IMPOSSIBLE";
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
