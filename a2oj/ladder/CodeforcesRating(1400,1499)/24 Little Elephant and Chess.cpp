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

void incr(pair<int, int> &f, bool c) {
    if (c) f.ff ++;
    else f.ss ++;
}

void solve() {
    loop(_, 0, 8) {
        pair<int, int> f = {0, 0};
        char c; cin >> c;
        bool prev = (c == 'W');
        incr(f, prev);
        loop(i, 1, 8) {
            cin >> c;
            bool cur = (c == 'W');
            if (cur == prev) {
                cout << "NO"; return;
            }
            incr(f, cur);
            prev = cur;
        }
        if (f.ff != 4 or f.ss != 4) {
            cout << "NO"; return;
        }
    }
    cout << "YES";
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
