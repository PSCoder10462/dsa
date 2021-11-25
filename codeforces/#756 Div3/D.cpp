// not accepted
/******************************************************/
#include <bits/stdc++.h>
using namespace std;
#define ll                long long
#define vi                vector<ll>
#define vvi               vector<vi>
#define pii               pair<ll, ll>
#define pb                push_back
#define mp                make_pair
#define mid(l, h)         ((l+h)/2)
#define loop(i, a, b)     for (auto i = a; i <= b; ++i)
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
    ll n; cin >> n;
    vvi tree(n+1);
    ll parent = -1;
    vi b(n+1);
    loop(i, 1, n) {
        ll p; cin >> p;
        b[i] = p;
        if (i == p) {
            parent = p; continue;
        }
        tree[p].pb(i);
    }
    vi p(n);
    for (auto &k: p) cin >> k;
    unordered_set<ll> choices = {parent};
    vi ans(n); ll mw = 0;
    for (auto i: p) {
        if (choices.find(i) != choices.end()) {
            ans[i-1] = mw; 
            mw = ans[b[i]-1] + ans[i-1] + 1;
            choices.erase(i);
            for (auto j: tree[i]) choices.insert(j);
        } else {
            cout << -1 << endl; return;
        }
    } 
    for (auto const &i: ans) cout << i << ' ';
    cout << endl;
}

int main () {
    clock_t start = clock();
    file_i_o();
    ll T;
    cin >> T;
    while (T--) {
      solve();
    }
#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\nExecuted in: " << (double)(end - start) / double(CLOCKS_PER_SEC)
    << " sec";
#endif
    return 0;
}
