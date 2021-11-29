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
    int a, b, n; cin >> n >> a >> b;
    vi v(n);
    v[0] = a; v[n-1] = b;
    int pos = 1;
    looprev(i, n, 1) {
        if (i == a || i == b) continue;
        v[pos++] = i;
    }
    int minn = a, maxx = b;
    loop(i, 0, n/2-1) {
        if (v[i] < minn) {cout << -1 << endl; return;}
    }
    loop(i, n/2, n-1) {
        if (v[i] > maxx) {cout << -1 << endl; return;}
    }
    for (ll i: v) cout << i << ' ';
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
