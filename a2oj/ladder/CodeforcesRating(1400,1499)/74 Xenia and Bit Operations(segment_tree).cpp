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

bool build(vi &seg_tree, vi &v, ll tl, ll tr, ll node = 1) {
    if (tl == tr) {
        // leaf node
        seg_tree[node] = v[tl];
        return true;
    }
    ll m = mid(tl, tr);
    bool OR = build(seg_tree, v, tl, m, 2*node);
    build(seg_tree, v, m+1, tr, 2*node+1);
    seg_tree[node] = (OR ?
        (seg_tree[node*2] | seg_tree[node*2 + 1])
        :
        (seg_tree[node*2] ^ seg_tree[node*2 + 1])
        );
    return !OR;
}

bool update(vi &seg_tree, vi &v, ll tl, ll tr, ll ind, ll val, ll node=1) {
    if (tl == tr) {
        // leaf node
        seg_tree[node] = val;
        v[ind] = val;
        return true;
    }
    ll m = mid(tl, tr);
    bool OR = true;
    if (ind <= m and tl <= ind) {
        // left child
        OR = update(seg_tree, v, tl, m, ind, val, 2*node);
    }
    if (ind > m and tr >= ind) {
        // right child
        OR = update(seg_tree, v, m+1, tr, ind, val, 2*node+1);
    }
    seg_tree[node] = (OR ?
        (seg_tree[node*2] | seg_tree[node*2 + 1])
        :
        (seg_tree[node*2] ^ seg_tree[node*2 + 1])
        );
    return !OR;
}

void solve() {
    ll n, q; cin >> n >> q;
    vi v((1ll<<n)+1);
    loop(i, 1, (1ll<<n)+1) cin >> v[i];
    vi seg_tree(2*(1ll << n)+1);
    build(seg_tree, v, 1, (1ll<<n));
    while (q--) {
        ll ind, val;
        cin >> ind >> val;
        update(seg_tree, v, 1, (1ll<<n), ind, val);
        cout << seg_tree[1] << endl;
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
