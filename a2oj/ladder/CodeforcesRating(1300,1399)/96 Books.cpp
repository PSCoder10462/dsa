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

void max_self(int &a, int b) {
    a = max(a, b);
}

void solve() {
    int n, t; cin >> n >> t;
    vector<int> pre(n+1, 0);
    loop(i, 1, n+1) {
        int k; cin >> k;
        pre[i] = pre[i-1] + k;
    }

    int ans = 0;

    loop(i, 1, n+1) {
        // incl book at i
        int pos = int(lower_bound(all(pre), t+pre[i-1]) - pre.begin());
        if (pos > n) {
            max_self(ans, pos-i);
            break;
        }
        if (pre[pos] == pre[i-1] + t) {
            max_self(ans, pos-i+1);
        } else {
            max_self(ans, pos-i);
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
