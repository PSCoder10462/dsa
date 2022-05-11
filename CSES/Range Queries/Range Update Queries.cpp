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

int n, q, a, b, val;
vi v, tree;

void build() {
    tree.assign(2*n, 0);
    loop(i, 0, n) tree[i+n] = v[i];
}

void update(int curlo=0, int curhi=n-1, int node=1) {
    if (curlo >= a and curhi <= b) {
        tree[node] += val;
        return;
    }
    if (curlo > b or curhi < a) return;
   
    int m = mid(curlo, curhi);
    int child = node << 1;
   
    update(curlo, m, child);
    update(m+1, curhi, child+1);
}

void query() {
    a += n;
    b += tree[a];
    a >>= 1;
    while (a >= 1) {
        b += tree[a];
        a >>= 1;   
    }
}

void solve() {
    cin >> n >> q;
    v.assign(n, 0);
    for (auto &i: v) cin >> i;
    while (__builtin_popcountll(n) != 1) ++n, v.pb(0);
    build();
    while (q--) {
        int ch; cin >> ch;
        if (ch==1) {
            cin >> a >> b >> val;
            --a, --b;
            update();           
        } else {
            b = 0;
            cin >> a;
            a--;
            query();
            cout << b << endl;
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
