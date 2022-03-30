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

vvi dir {
    {-1, 0, 1}, {1, 0, 2},
    {0, 1, 3}, {0, -1, 4}
};

void print_path(vector<vector<pii>> &vis, int r, int c) {
    string ans;
    while (vis[r][c].ff != -1) {
        switch(vis[r][c].ff) {
            case 1:
                ans.pb('U');
                r++;
            break;
            case 2:
                ans.pb('D');
                r--;
            break;
            case 3:
                ans.pb('R');
                c--;
            break;
            default:
                ans.pb('L');
                c++;
        }
    }
    reverse(all(ans));
    cout << "YES\n" << sz(ans) << endl << ans;
    exit(0);
}

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<char>> grid(n+2, vector<char>(m+2, '#'));
    
    pii A;
    queue<pii> monsters;
    
    vvi mons(n+2, vi (m+2, pinf));
    
    loop(i, 1, n+1)
        loop(j, 1, m+1) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A') 
                A = {i, j};
            if (grid[i][j] == 'M') {
                monsters.push({i, j});           
                mons[i][j] = 0;
            }
        }   
    
    while (!monsters.empty()) {
        auto [X, Y] = monsters.front();
        int S = mons[X][Y];
        monsters.pop();
        for (auto i: dir) {
            int x = X + i[0], y = Y + i[1];
            if (grid[x][y] != '#' 
                and
                mons[x][y] > S+1) {
                mons[x][y] = S+1;
                monsters.push({x, y});
            }
        }
    }
    
    vector<vector<pii>> vis(n+2, vector<pii> (m+2, {0, pinf}));
    vis[A.ff][A.ss] = {-1, 0};
    queue<pii> bfs;
    bfs.push(A);
    
    while (!bfs.empty()) {
        auto [X, Y] = bfs.front();
        int S = vis[X][Y].ss;
        bfs.pop();
        for (auto i: dir) {
            int x = X + i[0], y = Y + i[1];
            if (grid[x][y] != '#' 
                and
                vis[x][y].ss > S+1) {
                vis[x][y].ss = S+1;
                vis[x][y].ff = i[2];
                bfs.push({x, y});
            }
        } 
    }
    
    loop(i, 1, n+1) {
        if (vis[i][1].ss < mons[i][1]) {
            print_path(vis, i, 1);
        }
        if (vis[i][m].ss < mons[i][m]) {
            print_path(vis, i, m);
        }
    }
    loop(j, 1, m+1) {
        if (vis[1][j].ss < mons[1][j]) {
            print_path(vis, 1, j);
        }
        if (vis[n][j].ss < mons[n][j]) {
            print_path(vis, n, j);
        }
    }
    
    cout << "NO";
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
