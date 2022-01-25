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
    ll x, y; cin >> x >> y;
    int coord = 3;
    if (x > 0) {
        if (y > 0) coord = 1;
        else coord = 4;
    } else if (y > 0) coord = 2;

    x = abs(x); y = abs(y);

    ll a = x+y;

    switch(coord) {
        case 1:
            cout << 0 << ' ' << a << ' ' << a << ' ' << 0; 
            break;
        case 2: 
            cout << -a << ' ' << 0 << ' ' << 0 << ' ' << a; 
            break;
        case 3:
            cout << -a << ' ' << 0 << ' ' << 0 << ' ' << -a; 
            break;
        default:
            cout << 0 << ' ' << -a << ' ' << a << ' ' << 0; 
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
