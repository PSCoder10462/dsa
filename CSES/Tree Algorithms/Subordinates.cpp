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


void func(int n, vvi &Adj, vi &ans, int src, int parent=-1) {
    ans[src] = 1;
    for (auto i: Adj[src]) {
        if (i ^ parent) {
            func(n, Adj, ans, i, src);
            ans[src] += ans[i];
        }
    }
    cerr << src << ' ' << ans[src] << endl;
}

void solve() {
    int n; cin >> n;
    vvi Adj(n+1);
    loop(i, 2, n+1) {
        int par; cin >> par;
        Adj[i].pb(par);
        Adj[par].pb(i);
    }  
    vi ans(n+1, -1);
    func(n, Adj, ans, 1);
    loop(i, 1, n+1) cout << ans[i] - 1 << ' ';
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
