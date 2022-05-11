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

const int INF = 1e18;

int n;
vi v, tree;
int q_lo, q_hi;

void build() {
    tree.assign(2*n, INF);
    loop(i, 0, n) tree[i+n] = v[i];
    looprev(i, n-1, 1) {
        int child = (i<<1);
        tree[i] = min(tree[child], tree[child+1]);
    }
}

int query(int cur_lo = 0, int cur_hi = n-1, int node = 1) {
    if (cur_lo >= q_lo and cur_hi <= q_hi) return tree[node];
    if (cur_lo > q_hi or cur_hi < q_lo) return INF;
    
    int m = mid(cur_lo, cur_hi);
    int left = node << 1;
    int right = left + 1;
    return min(
        query(cur_lo, m, left), query(m+1, cur_hi, right)
        );
}

void solve() {
    int q;
    cin >> n >> q;
    v.assign(n, 0);
    for (auto &i: v) cin >> i;
    while (__builtin_popcountll(n) != 1) n++, v.pb(INF);
    build();  
    
    while (q--) {
        cin >> q_lo >> q_hi;
        --q_lo, --q_hi;
        cout << query() << endl; 
    }
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
