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

vector<vector<int>> graph(1);
vector<bool> vis;
queue<int> two_ind, one_ind;
vector<vector<int>> arr;


void dfs(int src) {
    queue<int> q;
    q.push(src);
    vector<int> temp;
    while (!q.empty()) {
        int t = q.front(); q.pop();
        temp.pb(t);
        vis[t] = true;
        for (auto i: graph[t]) {
            if (!vis[i]) {
                q.push(i);
                vis[i] = true;
            }
        }        
    }
    arr.pb(temp);
    if (temp.size() == 1) {
        one_ind.push((int)arr.size()-1);
    } else if (temp.size() == 2) {
        two_ind.push((int)arr.size()-1);
    }
}

void solve() {
    int v, e; cin >> v >> e;
    graph.resize(v+1);
    vis.resize(v+1, false);
    loop(_, 0, e) {
        int u, v; cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    
    loop(i, 1, v+1) {
        if (!vis[i])
            dfs(i);       
    }
    vector<vector<int>> ans; 
    if (two_ind.size() > one_ind.size()) {
        cout << -1; return;
    }
    while (!two_ind.empty()) {
        int two = two_ind.front(), one = one_ind.front();
        two_ind.pop(); one_ind.pop();
        ans.pb({arr[two][0], arr[two][1], arr[one][0]});
    }
    if (one_ind.size()%3) {
        cout << -1; return;
    }
    while(!one_ind.empty()) {
        int a = arr[one_ind.front()][0]; one_ind.pop();
        int b = arr[one_ind.front()][0]; one_ind.pop();
        int c = arr[one_ind.front()][0]; one_ind.pop();
        ans.pb({a, b, c});
    }
    for (auto i: arr) {
        if (i.size() > 3) {
            cout << -1; return;
        }
        if (i.size() == 3) {
            ans.pb(i);
        }
    }
    for(auto p: ans) {
        for(auto q: p) cout << q << ' ';
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
