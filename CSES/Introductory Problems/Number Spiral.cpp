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

void solve() {
    int n; cin >> n;
    while (n--) {
        int r, c; cin >> r >> c;
        int ans;
        if (r >= c) {
            if (r&1) {
                ans = (r-1)*(r-1)+1;
                ans += c-1;
            } else {
                ans = r*r;
                ans -= c-1;
            }
            
        } else {
            if (c&1) {
                ans = c*c;
                ans -= r-1;
            } else {
                ans = (c-1)*(c-1) + 1;
                ans += r-1;
            }
            
        }
        cout << ans << endl;
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
