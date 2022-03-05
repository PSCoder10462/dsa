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
    vector<map<ll, ll>> adj(n+1);
    loop(i, 0, m) {
        ll u, v; cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    loop(i, 1, n+1) {
        if (i > 1 and !adj[i][i-1])
            adj[i][i-1] = 2;
        if (i < n and !adj[i][i+1]) 
            adj[i][i+1] = 2;
    }
    const ll INF = 1e17;
    vi dist(n+1, INF);
    dist[1] = 0;
    priority_queue<ll, vi, greater<ll>> pq;
    pq.push(1);
    while (!pq.empty()) {
        ll v = pq.top();
        pq.pop();
    
        if (dist[v] == INF) break;
        
        for (auto [to, d]: adj[v]) {
            if (dist[v] + (d-1) < dist[to]) { 
                dist[to] = dist[v] + d-1;
                pq.push(to);
            }
        }
    }
    
    cout << dist[n] << endl;
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
