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

int n, m, k; 

void dfs(auto &v, auto &vis, pair<int, int> src) {
    if (src.ff < 0 or src.ff >= n or src.ss < 0 or src.ss >= m)
        return;
    if (k <= 0) return;
    if (v[src.ff][src.ss] != '.' or vis[src.ff][src.ss]) return;
    vis[src.ff][src.ss] = true;
    vector<pair<int, int>> dir = {
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}
    };
    for (auto [x, y] : dir) {
        dfs(v, vis, {src.ff+x, src.ss+y});
    }
    if (k > 0) {
        v[src.ff][src.ss] = 'X';
        --k;
    }
}

void solve() {
    cin >> n >> m >> k;
    vector<vector<char>> v(n, vector<char>(m));
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    pair<int, int> p = {-1, -1};
    loop(i, 0, n) {
        loop(j, 0, m) {
            cin >> v[i][j];
            if (v[i][j] == '.' and p.ff == -1)
                p = mp(i, j);
        }
    }
    
    dfs(v, vis, p);
    
    for(auto p: v) {
        for(auto q: p) cout << q;
        cout << endl;
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
