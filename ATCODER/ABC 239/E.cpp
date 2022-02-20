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

vector<int> val;
vector<vector<int>> adj;
vector<priority_queue<int, vector<int>, greater<int>>> pq;

void dfs(int child, int parent = -1) {
    for (auto &i: adj[child])
        if (i != parent)
            dfs(i, child);
    pq[child].push(val[child]);
    
    for (auto i: adj[child]) {
        if (i != parent) {
            auto temp = pq[i];
            while (!temp.empty()) {
                pq[child].push(temp.top());
                temp.pop();
                while (pq[child].size() > 20)
                   pq[child].pop(); 
            }
        }
    }
}


int query(int v, int k) {
    auto temp = pq[v];
    while ((int)temp.size() > k)
        temp.pop();
    return temp.top();
}

void solve() {
    int n, q; cin >> n >> q;
    val.resize(n+1);
    adj.resize(n+1);
    pq.resize(n+1);
    loop(i, 1, n+1)
        cin >> val[i];
    
    loop(i, 1, n) {
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1);
    while (q--) {
        // process queries
        int v, k; cin >> v >> k;
        cout << query(v, k) << endl;
    }
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
