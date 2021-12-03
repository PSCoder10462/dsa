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

bool check(vi &v, ll k, ll h, ll n) {
    ll dam = 0;
    loop(i, 0, n-2) {
        dam += min(k, v[i+1]-v[i]);
        if (dam >= h) return true;
    }
    dam += k;
    // cout << dam << ' ';
    return dam >= h;
}

void solve() {
    ll n, h; cin >> n >> h;
    vi v(n);
    for (auto &i: v) cin >> i;

    ll l = -1, r = min(h, (ll)1e18);
    
    while (l <= r) {
        ll m = mid(l, r);
        if (check(v, m, h, n)) r = m-1;
        else l = m+1; 
    }

    cout << l << endl;

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
