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

void solve() {
    const int INF = 1e5+5;
    vector<int> f(INF, 0);
    int n, k; cin >> n >> k;
    vector<int> v(n);
    for (auto &i: v) cin >> i;
    pair<int, int> ans = {-1, -1};
    int st, en; st = en = 0;
    int dist = 0;
    while (st < n and en < n) {
        bool flag = false;
        while (dist != k and en < n) {
            if (!f[v[en]]) {
                dist++;
            }
            f[v[en]]++;
            en++;
        }
        if (dist == k) flag = true;
        while (dist == k and st < n) {
            f[v[st]]--;
            if (f[v[st]] == 0) 
                dist--;
            st++;
        }
        if (flag and (ans.ff == -1 or ans.ss-ans.ff < en-st)) 
            ans = {st, en};
        
    }
    cout << ans.ff << ' ' << ans.ss;
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
