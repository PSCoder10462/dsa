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
    ll n; cin >> n;
    vi v(n);
    ll r = 0;
    for (auto &i: v) {
        cin >> i;
        r += i;
    }
    if (r%3) {
        cout << 0; return;
    }
    r /= 3;
    vi suf(n+1, 0);
    ll t = 0;
    looprev(i, n-1, 0) {
        t += v[i];
        if (t == r) {
            suf[i]++;
        }
        suf[i] += suf[i+1];
    }
    // for (auto const &i: suf) cout << i << ' ';
    // cout << endl;
    ll ans = 0;
    t = 0;
    loop(i, 0, n-1) {
        t += v[i];
        if (t == r) {
            ans += suf[i+2];
        }
    }
    cout << ans;
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
