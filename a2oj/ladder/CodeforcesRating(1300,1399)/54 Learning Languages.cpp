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

void dfs(auto &gr, auto &vis, auto src) {
    if (vis[src]) return;
    vis[src] = true;
    for (auto i: gr[src]) dfs(gr, vis, i);
}

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> v(m+1);
    int z = 0;
    loop(i, 0, n) {
        int t; cin >> t;
        if (t == 0) z++;
        loop(j, 0, t) {
            int l; cin >> l;
            v[l].pb(i+1);
        }
    }

    vector<vector<int>> gr(n+1);

    for (auto i: v) {
        loop(j, 0, (int)i.size()) 
            loop(k, j+1, (int)i.size()) {
                gr[i[j]].pb(i[k]);
                gr[i[k]].pb(i[j]);
            }
    }

    vector<bool> vis(n+1, false);
    int ctr = 0;
    loop(i, 1, n+1) {
        if (vis[i]) continue;
        ctr++;
        dfs(gr, vis, i);
    }
    cout << max(ctr-1, z);
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
