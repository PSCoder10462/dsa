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


void solve() {
    int n, m;
    cin >> n >> m;
    pii A, B;
    vector<vector<bool>> grid(n+2, vector<bool>(m+2, false));
    vvi vis(n+2, vi(m+2, 0));
    loop(i, 1, n+1) {
        loop(j, 1, m+1) {
            char c; cin >> c;
            grid[i][j] = (c == '.' || c == 'A' || c == 'B');
            if (c == 'A') {
                A = {i, j};
            }   
            if (c == 'B') {
                B = {i, j};
            }
        }
    }
    
    queue<pii> q;
    q.push(A);
    vis[A.ff][A.ss] = -1;
    
    vvi dir = {
        {-1, 0, 1}, {1, 0, 2}, {0, -1, 3}, {0, 1, 4}
    };
    
    while (!q.empty()) {
        int x = q.front().ff , y = q.front().ss;
        q.pop();
        for (auto i: dir) {
            if (grid[x+i[0]][y+i[1]] and !vis[x+i[0]][y+i[1]]) {
                vis[x+i[0]][y+i[1]] = i[2];
                q.push({x+i[0], y+i[1]});
            }
        }  
    }
    
    if (!vis[B.ff][B.ss]) {
        cout << "NO"; return;
    }
    
    string ans;
    int x = B.ff, y = B.ss;
    while (x != A.ff or y != A.ss) {
        switch(vis[x][y]) {
            case 1:
                ans.pb('U');
                x++;
            break;
            case 2:
                ans.pb('D');
                x--;
            break;
            case 3:
                ans.pb('L');
                y++;
            break;
            default: 
                ans.pb('R');
                y--;
        }
    }
    
    reverse(all(ans));
    cout << "YES" << endl;
    cout << sz(ans) << endl;
    cout << ans; 
    
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
