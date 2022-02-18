// segment tree sum range query with updation
// tested only locally ⚠️
// INPUT FORMAT:
// n, m (number of elements in array, number of queries)
// n integers (elements of array)
// m queries (each containing 4 int)
// l, r, ind, val
// OUTPUT FORMAT:
// segment tree(updated)
// array (updated)
// sum of the range from l to r, where array[ind] = val

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

void build(vector<int> &seg_tree, vector<int> &v, int node, int st, int en) {
    if (st == en) {
        seg_tree[node] = v[st];
        return;
    }
    int m = mid(st, en);
    build(seg_tree, v, 2*node+1, st, m);
    build(seg_tree, v, 2*node+2, m+1, en);
    seg_tree[node] = seg_tree[2*node+1] + seg_tree[2*node+2];
}

int query(vector<int> &seg_tree, int node, int l, int r, int tl, int tr) {
    if (tl >= l and tr <= r) 
        return seg_tree[node];
    if (tr < l or tl > r or tl > tr)
        return 0;
    int m = mid(tl, tr);
    return query(seg_tree, 2*node+1, l, r, tl, min(tr, m)) + query(seg_tree, 2*node+2, l, r, m+1, tr);
}

void update(vector<int> &seg_tree, vector<int> &v, int node, int tl, int tr, int ind, int val) {
    if (tl == tr) {
        v[ind] = val;
        seg_tree[node] = val;
        return;
    }
    int m = mid(tl, tr);
    if (ind <= m and tl <= ind) {
        // left child
        update(seg_tree, v, 2*node+1, tl, m, ind, val);
    }
    if (ind > m and ind <= tr) {
        // right child
        update(seg_tree, v, 2*node+2, m+1, tr, ind, val);
    }
    seg_tree[node] = seg_tree[2*node+1] + seg_tree[2*node+2];
}

void solve() {
    int n, q; cin >> n >> q;
    vector<int> v(n);
    for (auto &i: v) cin >> i;
    vector<int> seg_tree(2*n, 0);
    build(seg_tree, v, 0, 0, n-1);
    while (q--) {
        int l, r, ind, val; cin >> l >> r >> ind >> val;
        l--; r--; ind--; 
        update(seg_tree, v, 0, 0, n-1, ind, val);
        for (auto const &i: seg_tree) cout << i << ' ';
        cout << endl;
        for (auto const &i: v) cout << i << ' ';
        cout << endl << query(seg_tree, 0, l, r, 0, n-1) << endl;
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
