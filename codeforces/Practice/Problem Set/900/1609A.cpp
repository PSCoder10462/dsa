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

pair<int, int> func(int a) {
    int ctr = 0;
    while (!(a&1)) {
        ctr++;
        a >>= 1;
    }
    return mp(a, ctr);
}

void solve() {
    int n; cin >> n;
    vi a(n);
    for (auto &i: a) cin >> i;
    int p = 0;
    int maxx = -1, maxxp = -1;
    loop(i, 0, n-1) {
        auto [na, np] = func(a[i]);
        a[i] = na;
        p += np;
        if (maxx < na) {
            maxx = na; maxxp = i;
        }
    }

    ll ans = 0;
    loop(i, 0, n-1) {
        if (i == maxxp) {
            ans += (a[i] * (1ll<<p));
        } else {
            ans += a[i];
        }
    }
    cout << ans << endl;
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
