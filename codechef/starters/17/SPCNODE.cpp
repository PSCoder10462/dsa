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

vvi tree; 
vi subTreeSize;
vector<bool> dead; 

void getSubTreeSize(ll node, ll parent) {
    if (dead[node]) {subTreeSize[node] = 0; return;}
    subTreeSize[node] = 1;
    for (auto child: tree[node]) {
        if (child == parent) continue;
        getSubTreeSize(child, node);
        subTreeSize[node] += subTreeSize[child];
    }
}

ll getCentroid(ll src, ll parent, ll nodes) {
    for (auto edge: tree[src]) {
        if (dead[edge] or edge == parent) continue;
        if (subTreeSize[edge] > (nodes >> 1))
            return getCentroid(edge, src, nodes);
    }
    return src;
}

ll query(ll node) {
    ll result;
    cout << "? " << node << endl;
    fflush(stdout);
    cin >> result;
    return result;
}

void dfs(ll node) {
    getSubTreeSize(node, -1);
    ll centroid = getCentroid(node, -1, subTreeSize[node]);
    ll newNode = query(centroid);
    if (newNode == -1) {
        cout << "! " << node << endl;
        fflush(stdout); return;
    }
    dead[centroid] = true;
    dfs(newNode);
}

void solve() {
    int n; cin >> n;
    tree.resize(n+1);
    subTreeSize.assign(n+1, 0);
    dead.assign(n+1, false);
    loop(i, 1, n) {
        ll u, v; cin >> u >> v;
        tree[u].pb(v);
        tree[v].pb(u);
    }
    dfs(1);
}

int main () {
    clock_t start = clock();
    file_i_o();
    ll T;
    cin >> T;
    while (T--) {
      tree.clear(); dead.clear(); subTreeSize.clear();
      solve();
    }
#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\nExecuted in: " << (double)(end - start) / double(CLOCKS_PER_SEC)
    << " sec";
#endif
    return 0;
}
