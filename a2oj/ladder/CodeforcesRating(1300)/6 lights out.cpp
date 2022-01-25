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
    vvi m(5, vi (5, 0));
    vvi ans(5, vi(5, 1));
    loop(i, 1, 4)
        loop(j, 1, 4)
            cin >> m[i][j];

    loop(i, 1, 4) 
        loop(j, 1, 4) {
            ll t = m[i][j];
            ans[i-1][j] += t;
            ans[i+1][j] += t;
            ans[i][j-1] += t;
            ans[i][j+1] += t;
            ans[i][j] += t;
        }

    loop(i, 1, 4) {
        loop(j, 1, 4) cout << (ans[i][j]&1 ? 1 : 0);
        cout << endl;
    }

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
