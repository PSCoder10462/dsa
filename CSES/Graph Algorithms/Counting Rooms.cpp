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
#endif
}

void dfs(auto &graph, auto &vis, int r, int c) { 

    vis[r][c] = true;
    
    vvi dir {
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}
    };
    
    for (auto i: dir) {
        if (graph[r+i[0]][c+i[1]] and !vis[r+i[0]][c+i[1]])
            dfs(graph, vis, r+i[0], c+i[1]);
    }

}

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<bool>> graph(n+2, vector<bool> (m+2, false));
    vector<vector<bool>> vis(n+2, vector<bool> (m+2, false));
    loop(i, 1, n+1) {
        loop(j, 1, m+1) {
            char c; cin >> c;
            graph[i][j] = (c=='.');
        }
    }
    
    int ans = 0;
    loop(i, 1, n+1) {
        loop(j, 1, m+1) {
            if (graph[i][j] and !vis[i][j]) {
                ans++;
                dfs(graph, vis, i, j);
            }
        }
    }
    
    cout << ans;
}

int32_t main () {
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
