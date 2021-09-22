// Bellman-Ford Algorithm

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

class Edge {
public:
    int src, dest, weight;
    Edge(int s, int d, int w);
};

Edge::Edge(int s, int d, int w) : src(s), dest(d), weight(w) {};

class Graph {
public:
    int V, E;
    vector<Edge> edges;
    Graph();
};

Graph::Graph() {
    cin >> V >> E;
    loop(i, 1, E) {
        int u, v, w; cin >> u >> v >> w;
        Edge e (u, v, w);
        edges.pb(e);
    }
}

bool check = false;

vi bellmanFord(Graph *graph, int src = 0) {

    // init
    vi dist (graph->V, pinf);
    dist[src] = 0;

    // relax edges
    loop(i, 1, graph->V - 1) {
        loop (j, 0, graph->E - 1) {
            Edge e = graph->edges[j];
            int u = e.src, v = e.dest, w = e.weight;
            if (dist[u] != pinf and dist[u] + w < dist[v]) 
                dist[v] = dist[u] + w;
        }
    }

    // check negative cycle
    loop(i, 0, graph->E-1) {
        Edge e = graph->edges[i];
        int u = e.src, v = e.dest, w = e.weight;
        if (dist[u] != pinf and dist[u] + w < dist[v]) { 
            cout << "Negative edge cycle report!!!";
            check = true;
            break;
        }
    }

    return dist;
}

void solve() {
    Graph *graph = new Graph();

    vi dist = bellmanFord(graph, 0);

    if (!check)
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
