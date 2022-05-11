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

int n, q_lo, q_hi;
vi v, tree;

void build() {
    while (__builtin_popcountll(n) != 1) ++n, v.pb(0);
    tree.assign(2*n, 0);
    loop(i, 0, n) tree[i+n] = v[i];
    looprev(i, n-1, 1) {
        int child = i << 1;
        tree[i] = tree[child] + tree[child+1];
    }
}

int query(int cur_lo=0, int cur_hi=n-1, int node=1) {
    if (cur_lo >= q_lo and cur_hi <= q_hi) return tree[node];
    if (cur_lo > q_hi || cur_hi < q_lo) return 0;
    int m = mid(cur_lo, cur_hi);
    int left = (node << 1);
    int right = left + 1;
    return (
        query(cur_lo, m, left) + query(m+1, cur_hi, right)
        );
}

void update(int ind, int val) {
    v[ind] = val;
    ind += n;
    tree[ind] = val;
    ind >>= 1;
    while (ind >= 1) {
        int child = ind << 1;
        tree[ind] = tree[child] + tree[child+1];
        ind >>= 1;
    }
}

void solve() {
    int q;
    cin >> n >> q;
    v.assign(n, 0);
    for (auto &i: v) cin >> i;
    build();
    while (q--) {
        int ch;
        cin >> ch;
        switch(ch) {
            case 1:
                int ind, val; cin >> ind >> val;
                --ind;
                update(ind, val);
            break;
            case 2:
                cin >> q_lo >> q_hi;
                -- q_lo, -- q_hi;
                cout << query() << endl;
            break;
        }
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
