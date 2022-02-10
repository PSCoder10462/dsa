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
    int n, k; cin >> n >> k;
    vector<pii> max_after(n+1, {-1, -1});
    // index, value
    vi pre(n+1, 0);
    loop(i, 1, n+1) {
        int a; cin >> a;
        pre[i] = pre[i-1]+a;
    }    
    looprev(i, n-k, 0) {
        ll cur = pre[i+k]-pre[i];
        if (max_after[i+1].ff <= cur) {
            max_after[i].ff = cur;
            max_after[i].ss = i;
        } else 
            max_after[i] = max_after[i+1];
    }
    
    pair<int, int> ans={-1, -1};
    ll maxx = -1;
    loop(i, 0, n-(2*k)+1) {
        ll val = pre[i+k]-pre[i] + max_after[i+k].ff;
        if (maxx < val) {
            maxx = val;
            ans = mp(i+1, max_after[i+k].ss+1);
        }
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
