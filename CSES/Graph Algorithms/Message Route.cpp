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

void dijkstra(vvi &graph, vi &dist, vi &path) {
    int src = 1;
    priority_queue<int, vi, greater<int>> min_heap;
    min_heap.push(src);
    dist[src] = 0;
    while (!min_heap.empty()) {
        int node = min_heap.top();
        min_heap.pop();
        for (auto i: graph[node]) {
            if (dist[i] == -1 || dist[i] > dist[node]+1) {
                dist[i] = dist[node]+1;
                min_heap.push(i);
                path[i] = node;
            }
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
    
    vi path(n+1);
    vi dist(n+1, -1);
    
    dijkstra(graph, dist, path);
    
    if (dist[n] == -1) {
        cout << "IMPOSSIBLE";
        return;
    } 
    vi ans;
    int comp = n;
    ans.pb(n);
    while (comp != 1) {
        ans.pb(path[comp]);
        comp = path[comp];
    }
            
    cout << sz(ans) << endl;
    looprev(i, sz(ans), 1) {
        cout << ans[i-1] << ' ';
    }
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
