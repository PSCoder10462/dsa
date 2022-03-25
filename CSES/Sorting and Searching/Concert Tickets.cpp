/******************************************************/
#include <bits/stdc++.h>
using namespace std;
#define int               long long
#define vi                vector<int>
#define vvi               vector<vi>
#define all(v)            v.begin(), v.end()
#define pii               pair<int, int>
#define pb                push_back
#define sz(container)     (container.size()) 
#define mid(l, h)         (l+(h-l)/2)
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
    int n, m;
    cin >> n >> m;
    multiset<int> tickets;
    loop(i, 0, n) {
        int t; cin >> t;
        tickets.insert(t);
    }
    loop(z, 0, m) {
        int p; cin >> p;
        if (sz(tickets) == 0) {
            cout << -1 << endl; continue;
        }
        auto it = tickets.lower_bound(p);
        if (*it > p and it == tickets.begin()) {
            cout << -1 << endl;
            continue;
        }
        if (it == tickets.end() || *it > p) {
            --it;
        }
        cout << *it << endl;
        tickets.erase(it);
    }
}

int32_t main () {
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
