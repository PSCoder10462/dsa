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

bool color_graph(vvi &adj, vi &color, int start = 0) {
    if (!color[start]) color[start] = 1;

    queue<ll> q;
    q.push(start);

    while (!q.empty()) {
        ll t = q.front(); q.pop();
        for (auto i: adj[t]) {
            if (!color[i]) {
                color[i] = (color[t] == 1 ? 2 : 1);
                q.push(i);
            }
            else if (color[i] == color[t]) return false;
        }
    }

    return true;
}

void solve() {
    int n, m;
    cin >> n >> m;

    vvi adj(n);

    for (int i = 0; i < m; i++) {
        ll u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    vi color (n, 0);

    loop(i, 0, n-1) {
        if (!color[i])
            if (!color_graph(adj, color, i)) {
                cout << "NO"; return;
            }
    }

    cout << "YES";
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
