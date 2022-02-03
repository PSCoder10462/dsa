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
    ll n; string s; cin >> n >> s;
    vector<pair<ll, char>> v(26);
    loop(i, 0, 26) v[i].ss = (char)('a'+i);
    for (auto &i: s) 
        v[i-'a'].ff++;
    sort(all(v));
    if (v[25].ff > n/2 or n&1) {
        cout << "NO\n"; return;
    }
    string ans;
    for (auto [freq, ch]: v) {
        loop(i, 0, freq)
            ans.pb(ch);
    }
    // if (ans[n/2] == ans[n/2-1]) swap(ans[0], ans[n/2-1]);
    reverse(ans.begin(), ans.begin() + n/2);
    cout << "YES\n" << ans << endl;
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
