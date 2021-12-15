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
    ll t, sx, sy, ex, ey;
    cin >> t >> sx >> sy >> ex >> ey;
    bool ce = sx < ex; 
    bool cs = sy > ey;

    ll hr = abs(sx-ex);
    ll vr = abs(sy-ey);

    ll h = 0, v = 0;

    loop(i, 0, t) {
        char c; cin >> c;
        switch(c) {
            case 'E': if (ce and h < hr) h++;
                break;
            case 'W': if (!ce and h < hr) h++;
                break;
            case 'N': if (!cs and v < vr) v++;
                break;
            default: if (cs and v < vr) v++;
        }        
        if (h == hr and v == vr) {
            cout << i + 1; return;
        }
    }

    cout << -1;
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
