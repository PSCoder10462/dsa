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
    freopen("error.txt", "w", stderr);
#endif
}
 
void solve() {
    int n, m; cin >> n >> m;
    vector<vector<pii>> Adj(n+1);
    loop(i, 0, m) {
        int u, v, w; cin >> u >> v >> w;
        Adj[u].pb({v, w});
    }
    
    const int INF = 1e16;
    
    vi dist(n+1, INF);
    
    dist[1] = 0;
    
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    
    pq.push({0, 1});
    
    while (!pq.empty()) {
        auto [lw, node] = pq.top();
        pq.pop();
        if (lw != dist[node]) continue;
        for (auto [i, w]: Adj[node]) {
            if (dist[i] > dist[node] + w) {
                dist[i] = dist[node] + w;
                pq.push({dist[i], i});
            }
        }
    }
    
    loop(i, 1, n+1) cout << dist[i] << ' ';
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
