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

int n, q, qlo, qhi;
vi v, tree;

void inp_init() {
    cin >> n >> q;
    v.assign(n, 0);
    for (auto &i: v) cin >> i;
    while (__builtin_popcountll(n) != 1) ++n, v.pb(0);
    tree.assign(2*n, 0);
}

void build() {
    loop(i, 0, n) tree[i+n] = v[i];
    looprev(i, n-1, 1) tree[i] = tree[i*2] ^ tree[i*2 + 1];
}

int query(int curlo=0, int curhi=n-1, int node=1) {
    if (curlo >= qlo and curhi <= qhi) return tree[node];
    if (curlo > qhi or curhi < qlo) return 0;
    int m = mid(curlo, curhi);
    int l = node << 1;
    int r = l+1;
    return (
        query(curlo, m, l) ^ query(m+1, curhi, r)
        );
}

void call_q() {
    while (q--) {
        cin >> qlo >> qhi;
        --qlo, --qhi;
        cout << query() << endl;
    }
}

void solve() {
    inp_init();
    build();
    call_q();
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
