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

int Get(vector<int> &arr, int node) {
    while (arr[node] != node) node = arr[node];
    return node;
}

void Union(vector<int> &arr, vector<int> &size, int a, int b) {
    int ra = Get(arr, a), rb = Get(arr, b);
    if (ra == rb) return;
    if (size[ra] <= size[rb]) {
        arr[ra] = rb;
        size[rb] += size[ra];
    } else {
        arr[rb] = ra;
        size[ra] += size[rb];
    }
}

void solve() {
    int n, m; cin >> n >> m;
    vector<int> arr(n), size(n, 1);
    vector<set<int>> v(n);
    loop(i, 0, n) arr[i] = i;
    int zer = 0;
    
    loop(i, 0, n) {
        int j; cin >> j;
        zer = (j ? zer : zer+1);
        while (j--) {
            int l; cin >> l;
            v[i].insert(l);
            loop(k, 0, i) {
                if (v[k].find(l) != v[k].end()) {
                    Union(arr, size, k, i);
                    break;
                }
            }
        }
    }

    if (zer == n) {cout << n; return;}

    int ctr = 0;
    vector<bool> vis(n+1, false);
    for (auto i: arr) {
        int j = Get(arr, i);
        if (vis[j]) continue;
        vis[j] = true;
        ctr++;
    }
    cout << ctr-1;
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
