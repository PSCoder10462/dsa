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
    string s; cin >> s;
    ll i = -1;
    while (s[++i] ==  '?');
    char cur = s[i];
    char prev = cur == 'R' ? 'B' : 'R';
    string ans = "";
    looprev(j, i-1, 0) {
        ans.pb(prev);
        prev = prev == 'R' ? 'B' : 'R';
    }
    reverse(ans.begin(), ans.end());
    loop(j, i, n-1) {
        if (s[j] != '?' and s[j] != cur) {
                ans.pb(s[j]); 
                continue;
        }
        ans.pb(cur); 
        cur = cur == 'R' ? 'B' : 'R';
    }
    cout << ans << endl;;
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