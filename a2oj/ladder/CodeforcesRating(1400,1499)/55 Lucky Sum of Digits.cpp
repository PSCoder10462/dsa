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

const int INF = 1e5+5;

void solve() {
    int n; cin >> n;
    pair<int, int> req = mp(INF, INF);
    for (int i=0; i*4 <= n; ++i) {
        int t = n-(4*i);
        if (t%7 == 0) {
            int s = t/7;
            if (i + s <= req.ff + req.ss) 
                req = mp(i, s);
        }
    }
    if (req.ff == INF and req.ss == INF) {
        cout << -1; return;
    }
    if (req.ff != INF) {
        loop(i, 0, req.ff) 
            cout << 4;
    }
    if (req.ss != INF) {
        loop(i, 0, req.ss) 
            cout << 7;
    }
    cout << endl;
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
