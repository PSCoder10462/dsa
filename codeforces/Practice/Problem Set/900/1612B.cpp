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
    int n, a, b; cin >> n >> a >> b;
    
    if (b < a) {
        if (b == n/2 and a == n/2+1) {
            loop(i, n/2+1, n) cout << i << ' '; 
            loop(i, 1, n/2) cout << i << ' '; 
        } else cout << -1;
        cout << endl; return;
    }

    vi left, right;

    left.pb(a); right.pb(b);

    loop(i, 1, a-1) right.pb(i);
    loop(i, b+1, n) left.pb(i);

    if ((int)max(left.size(), right.size()) > n/2) {
        cout << -1 << endl; return;
    }

    for (auto i: left) cout << i << ' ';
    loop(i, a+1, b-1) cout << i << ' ';
    for (auto i: right) cout << i << ' '; 
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
