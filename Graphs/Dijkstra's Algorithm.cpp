// Dijkstra's algo using minHeap and adjacency list (undirected graph)

/******************************************************/
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

vi dijkstra(vector<vector<pii>> &adj, int V, int src) {
    vi dist(V, pinf);
    dist[src] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> minHeap;
    minHeap.push({0, src});

    while (!minHeap.empty()) {
        pii cur = minHeap.top(); minHeap.pop();
        for (pii node: adj[cur.ss]) {
            if (dist[node.ss] > dist[cur.ss] + node.ff) {
                dist[node.ss] = dist[cur.ss] + node.ff;
                minHeap.push({dist[node.ss], node.ss});
            }
        }
    }

    return dist;
}

void solve() {
    int V, E; cin >> V >> E;
    vector<vector<pii>> adj(V);

    loop(i, 1, E) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({w, v});
        adj[v].pb({w, u});
    }

    // {weight, vertex}
    cout << "Adjacency List:\n";
    for(auto p: adj) {
        for(auto q: p) cout << '{' << q.ff << ',' << q.ss << "} ";
        cout << endl;
    }


    vi dist = dijkstra(adj, V, 0);

    cout << "\nDistances:\n";
    for (auto const &i: dist) cout << i << ' ';
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
