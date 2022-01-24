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

void solve() {
    int v, e; cin >> v >> e;
    vector<vector<int>> graph(v+1);
    vector<int> ind (v+1, 0);
    vector<bool> vis(v+1, false);
    loop(i, 0, e) {
        int u, w; cin >> u >> w;
        ind[w]++;
        graph[u].pb(w);
    }

    vector<int> dp(v+1, 0);
    loop(i, 1, v+1) {
        queue<int> q;
        if (!ind[i] and !vis[i])
            q.push(i);
        while (!q.empty()) {
            int u = q.front();
            // cout << u << ' ';
            q.pop();
            for (auto &j: graph[u]) {
                dp[j] = max(dp[j], dp[u]+1);
                ind[j]--;
                if (!ind[j] and !vis[j]) {
                    vis[j] = true; 
                    q.push(j);
                }
            }
                
        }
    }
    cout << *max_element(all(dp));
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
