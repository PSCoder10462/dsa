// 1 based indexing/input is used
/******************************************************/
#include <bits/stdc++.h>
using namespace std;
#define ll                long long
#define vi                vector<ll>
#define vvi               vector<vi>
#define vb                vector<bool>
#define vvb               vector<vb>
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

void dfs(vvb &adj, int V, vb &visited, int starter=1) {
    cout << starter << ' ';

    visited[starter] = true;

    loop(i, 1, V) {
        if (adj[starter][i] and !visited[i]) 
            dfs(adj, V, visited, i);
    }
}

void solve() {
    // vertices, edges
    int V, E;
    cin >> V >> E;

    // adjacency matrix
    vvb adj(V+1, vb(V+1, false));

    // input graph
    loop(i, 1, E) {
        int v1, v2; cin >> v1 >> v2;
        adj[v1][v2] = adj[v2][v1] = true;
    }

    vb visited(V+1, false);

    dfs(adj, V, visited);
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
