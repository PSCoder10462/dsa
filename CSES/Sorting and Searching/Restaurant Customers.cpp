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


int find_left(vector<pii> &v, int n) {
    int lo = -1, hi = n+1;
    while (lo+1 != hi) {
        int m = mid(lo, hi);
        if (v[m].ss > v[n].ff) hi = m;
        else lo = m;
    }
    return lo+1;
}

void solve() {
    int n; cin >> n;
    
    set<pii> s;
    
    loop(i, 0, n) {
        int e, l; cin >> e >> l;
        s.insert({e, 1});
        s.insert({l+1, -1});
    }
    
    int ans = 0;
    int c = 0;
    for (auto [a, b] : s) {
        c += b;
        ans = max(ans, c);
    }
    
    cout << ans;
}

int32_t main () {
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
