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
    vi b(2*n);
    
    for (auto &i: b) cin >> i;
    
    sort(b.begin(), b.end());

    vi ans;
    ll i = 0;
    
    while (i < 2*n-1) {
        if ((n&1 and i == n-1) or (!(n&1) and i == n-2)) {
            loop(j, 1, 2) {
                if (i+j > 2*n-1) break;
                if (b[i+j] != b[i]) {cout << -1 << endl; return;}
            }
            i++; continue;
        }
        if (b[i] != b[i+1]) {cout << -1 << endl; return;}
        ans.pb(b[i]);
        i += 2;
    }

    ans.pb(b[2*n-1]);
    
    loop(i, 1, ans.size()-1) {
        if (ans[i] == ans[i-1]) {
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
