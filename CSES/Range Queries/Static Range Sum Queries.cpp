// solved it using segment trees, ofcourse one could use simple prefix sum array! 

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

int n, q; 
vi v, tree;

void build() {
    tree.assign(2*n, 0);
    loop(i, 0, n) tree[i+n] = v[i];
    looprev(i, 2*n-1, 2) tree[i/2] += tree[i];
}

int query(int q_lo, int q_hi, int cur_lo=0, int cur_hi=n-1,int node = 1) {
    if (cur_lo >= q_lo and cur_hi <= q_hi) return tree[node];
    if (cur_lo > q_hi || cur_hi < q_lo) return 0;
    
    int m = mid(cur_lo, cur_hi);
    
    int left = node << 1;
    int right = 1 + left;
    
    return 
        query(q_lo, q_hi, cur_lo, m, left)
            +
        query(q_lo, q_hi, m+1, cur_hi, right);
}

void solve() {
    cin >> n >> q;
    v.assign(n, 0);
    for (auto &i: v) cin >> i;
    while (__builtin_popcountll(n) != 1) n++, v.pb(0);
    build();
    
    // for (auto const &i: tree) cerr << i << ' ';
        
    while (q--) {
        int l, r; cin >> l >> r;
        --l, --r;
        cout << query(l, r) << endl;
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
